const fs = require('fs');
const os = require('os');
const path = require('path');

const RTHRDS = /^OMP_NUM_THREADS=(\d+)/m;
const RELEMS = /^# Elements (.+)/m;
const RRESLT = /^\[(.+?) ms\] \[(.+?)\] (\w+)(?: \{sch_kind: (\w+), chunk_size: (\d+)\})?/m;




// *-FILE
// ------

function readFile(pth) {
  var d = fs.readFileSync(pth, 'utf8');
  return d.replace(/\r?\n/g, '\n');
}

function writeFile(pth, d) {
  d = d.replace(/\r?\n/g, os.EOL);
  fs.writeFileSync(pth, d);
}




// *-CSV
// -----

function writeCsv(pth, rows) {
  var cols = Object.keys(rows[0]);
  var a = cols.join()+'\n';
  for (var r of rows)
    a += [...Object.values(r)].map(v => `"${v}"`).join()+'\n';
  writeFile(pth, a);
}




// *-LOG
// -----

function readLogLine(ln, data, state) {
  if (RTHRDS.test(ln)) {
    var [, omp_num_threads] = RTHRDS.exec(ln);
    var omp_num_threads = parseFloat(omp_num_threads);
    if (!data.has(omp_num_threads)) data.set(omp_num_threads, []);
    state = {omp_num_threads};
  }
  else if (RELEMS.test(ln)) {
    var [, elements] = RELEMS.exec(ln);
    state.elements = parseFloat(elements);
  }
  else if (RRESLT.test(ln)) {
    var [, time, sum, technique, schedule_kind, chunk_size] = RRESLT.exec(ln);
    data.get(state.omp_num_threads).push(Object.assign({}, state, {
      time:          parseFloat(time),
      sum:           parseFloat(sum),
      technique,
      schedule_kind: schedule_kind || '',
      chunk_size:    parseFloat(chunk_size || '0')
    }));
  }
  return state;
}

function readLog(pth) {
  var text = readFile(pth);
  var lines = text.split('\n');
  var data = new Map();
  var state = null;
  for (var ln of lines)
    state = readLogLine(ln, data, state);
  return data;
}




// PROCESS-*
// ---------

function processCsv(data) {
  var a = [];
  for (var rows of data.values())
    a.push(...rows);
  return a;
}




// MAIN
// ----

function main(cmd, log, out) {
  var data = readLog(log);
  if (path.extname(out)==='') cmd += '-dir';
  switch (cmd) {
    case 'csv':
      var rows = processCsv(data);
      writeCsv(out, rows);
      break;
    case 'csv-dir':
      for (var [elements, rows] of data)
        writeCsv(path.join(out, elements+'.csv'), rows);
      break;
    default:
      console.error(`error: "${cmd}"?`);
      break;
  }
}
main(...process.argv.slice(2));

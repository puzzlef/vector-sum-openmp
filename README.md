Comparing various *schedules* for *OpenMP-based* **vector element sum**.

In this experiment, we summed together all values of a floating-point vector
`x`, with number of **elements** from `1E+6` to `1E+9` using OpenMP. Each
element count was attempted with various **OpenMP schedule configs**, running
each config 5 times to get a good time measure. Sum here represents any
`reduce()` operation that processes several values to a single value. Results
indicate a **schedule-kind** of `auto`/`guided` to be suitable.

All outputs are saved in a [gist] and a small part of the output is listed here.
Some [charts] are also included below, generated from [sheets]. This experiment
was done with guidance from [Prof. Kishore Kothapalli] and
[Prof. Dip Sankar Banerjee].

<br>

```bash
$ g++ -std=c++17 -O3 -fopenmp main.cxx
$ ./a.out

# OMP_NUM_THREADS=12
# # Elements 1e+06
# [00001.687 ms] [1.644725] sumSeq
# [00003.840 ms] [1.644881] sumOmp {sch_kind: static, chunk_size: 1}
# [00001.138 ms] [1.644891] sumOmp {sch_kind: static, chunk_size: 2}
# [00000.523 ms] [1.644898] sumOmp {sch_kind: static, chunk_size: 4}
# ...
#
# ...
# [00162.374 ms] [1.644725] sumOmp {sch_kind: auto, chunk_size: 16384}
# [00178.243 ms] [1.644725] sumOmp {sch_kind: auto, chunk_size: 32768}
# [00162.962 ms] [1.644725] sumOmp {sch_kind: auto, chunk_size: 65536}
```

[![](https://i.imgur.com/y6iakEW.png)][sheetp]
[![](https://i.imgur.com/bDR4ydK.png)][sheetp]
[![](https://i.imgur.com/RWeyzab.png)][sheetp]
[![](https://i.imgur.com/x9fXslg.png)][sheetp]

<br>
<br>


## References

- [What's the difference between "static" and "dynamic" schedule in OpenMP?](https://stackoverflow.com/a/10852852/1413259)
- [OpenMP Dynamic vs Guided Scheduling](https://stackoverflow.com/a/43047074/1413259)

<br>
<br>


[![](https://i.imgur.com/nTqPMNA.jpg)](https://knowyourcodelyokofacts.tumblr.com/post/49493220478/jeremy-belpois-jeremy-is-known-to-have-been)<br>
[![ORG](https://img.shields.io/badge/org-puzzlef-green?logo=Org)](https://puzzlef.github.io)
[![DOI](https://zenodo.org/badge/424940871.svg)](https://zenodo.org/badge/latestdoi/424940871)


[Prof. Dip Sankar Banerjee]: https://sites.google.com/site/dipsankarban/
[Prof. Kishore Kothapalli]: https://faculty.iiit.ac.in/~kkishore/
[gist]: https://gist.github.com/wolfram77/89a017ee65c92ca062e21b23b987d321
[charts]: https://imgur.com/a/sb8jZko
[sheets]: https://docs.google.com/spreadsheets/d/1m0IhoxjrarXYqE6yr_NdHlIrNn9QpkkOrHPidmNTcbo/edit?usp=sharing
[sheetp]: https://docs.google.com/spreadsheets/d/e/2PACX-1vTlIUrPp-YXzG2Svlwrg-uVZLja-csxl1m6iMEv9RXC0vxo9O_Ra5S4_ztl1PUg79QU4I3XefV3V7dJ/pubhtml

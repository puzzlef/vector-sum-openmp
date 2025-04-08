Comparing performance of *sequential* vs *OpenMP-based* **vector element sum**.

<br>


### Adjusting OpenMP schedule

In this experiment ([adjust-schedule]), we sum together all values of a
floating-point vector `x`, with number of **elements** from `1E+6` to `1E+9`
using OpenMP. We attempt each element with various **OpenMP schedule**
**configs**, running each config 5 times to get a good time measure. Sum here
represents any `reduce()` operation that processes several values to a single
value. Our results indicate a **schedule-kind** of `auto`/`guided` to be suitable.

[adjust-schedule]: https://github.com/puzzlef/vector-sum-openmp/tree/adjust-schedule

<br>


### Comparison with Sequential approach

In this experiment ([compare-sequential], [main]), we compare the performance
between finding `Σx` using a single thread (**sequential**) or **OpenMP**. While
it might seem that **OpenMP** method would be a clear winner, our results
indicate it is dependent upon the workload, i.e., from `10⁵` elements, OpenMP
approach performs *better* than sequential. All outputs are saved in [gist].
Some [charts] are also included below, generated from [sheets].

[compare-sequential]: https://github.com/puzzlef/vector-sum-openmp/tree/compare-sequential
[main]: https://github.com/puzzlef/vector-sum-openmp

<br>

[![](https://i.imgur.com/gdJQIVJ.png)][sheetp]
[![](https://i.imgur.com/4VKbI6Q.png)][sheetp]

<br>
<br>


## References

- [Parallel for loop in openmp](https://stackoverflow.com/a/11773714/1413259)
- [What's the difference between “static” and “dynamic” schedule in OpenMP?](https://stackoverflow.com/a/10852852/1413259)
- [Git pulling a branch from another repository?](https://stackoverflow.com/a/46289324/1413259)

<br>
<br>


[![](https://i.imgur.com/Va4qBPD.jpg)](https://www.youtube.com/watch?v=0XTLuFpuAtE)
![](https://ga-beacon.deno.dev/G-KD28SG54JQ:hbAybl6nQFOtmVxW4if3xw/github.com/puzzlef/vector-sum-openmp)

[gist]: https://gist.github.com/wolfram77/9b90248012dda38727d57e12786ff40c
[charts]: https://photos.app.goo.gl/ruBBeXTz6vEATFQc6
[sheets]: https://docs.google.com/spreadsheets/d/1ZBp9TFxisTn_8_7_X_2HSPt_SbmP16gUW6_fiMtr8rc/edit?usp=sharing
[sheetp]: https://docs.google.com/spreadsheets/d/e/2PACX-1vTPFQlVfelJvgStWlpUnmAWcTZZXpYbL4APW0nc0djGLIGJdWABXx6S2QLkrxHbct_jnXJ51JlB7cv7/pubhtml

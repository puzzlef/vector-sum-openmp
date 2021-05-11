Performance of sequential execution based vs OpenMP based vector multiply.

This experiment was for comparing the performance between:
1. Find `x*y` using a single thread (**sequential**).
2. Find `x*y` accelerated using **OpenMP**.

Here `x`, `y` are both floating-point vectors. Both approaches were attempted
on a number of vector sizes, running each approach 5 times per size to get a
good time measure. While it might seem that **OpenMP** method would be a clear
winner, the results indicate it is not the case. This is possibly becuase of
high communication costs, and not enough computational workload as indicated
by [this answer].

```bash
$ g++ -O3 -fopenmp main.cxx
$ ./a.out

# [00000.001 ms; 1e+04 elems.] multiply
# [00000.001 ms; 1e+04 elems.] multiplyOmp
#
# [00000.015 ms; 1e+05 elems.] multiply
# [00000.015 ms; 1e+05 elems.] multiplyOmp
#
# [00000.158 ms; 1e+06 elems.] multiply
# [00000.158 ms; 1e+06 elems.] multiplyOmp
#
# [00002.145 ms; 1e+07 elems.] multiply
# [00002.145 ms; 1e+07 elems.] multiplyOmp
#
# [00022.215 ms; 1e+08 elems.] multiply
# [00022.215 ms; 1e+08 elems.] multiplyOmp
#
# [00218.564 ms; 1e+09 elems.] multiply
# [00218.564 ms; 1e+09 elems.] multiplyOmp
```

<br>
<br>


## References

- [open MP - dot product][this answer]
- [What's the difference between “static” and “dynamic” schedule in OpenMP?](https://stackoverflow.com/a/10852852/1413259)

<br>
<br>

[![](https://i.imgur.com/XDeCwiz.jpg)](https://www.youtube.com/watch?v=0XTLuFpuAtE)

[this answer]: https://stackoverflow.com/a/5368572/1413259

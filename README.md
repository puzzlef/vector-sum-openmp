Comparing various launch configs for CUDA based vector multiply.

`TODO!`

Two floating-point vectors `x` and `y`, with number of **elements** from `1E+6` to `1E+9` were multiplied using CUDA. Each element count was attempted with various **CUDA launch configs**, running each config 5 times to get a good time measure. Multiplication here represents any memory-aligned independent operation, or a `map()` operation. Results indicate that a **grid_limit** of `16384/32768`, and a **block_size** of `128/256` to be suitable for both **float** and **double**. Using a **grid_limit** of `MAX` and a **block_size** of `256` could be a decent choice.

All outputs are saved in [out](out/) and a small part of the output is listed here. [Nsight Compute] profile results are saved in [prof](prof/). Some [charts] are also included below, generated from [sheets]. This experiment was done with guidance from [Prof. Dip Sankar Banerjee] and [Prof. Kishore Kothapalli].

<br>

```bash
$ nvcc -std=c++17 -Xcompiler -O3 main.cu
$ ./a.out

# ...
#
# # Elements 1e+07
# [00002.138 ms] [1.644725] multiplySeq
# [00000.243 ms] [1.644725] multiplyCuda<<<1024, 32>>>
# [00000.179 ms] [1.644725] multiplyCuda<<<1024, 64>>>
# [00000.170 ms] [1.644725] multiplyCuda<<<1024, 128>>>
# [00000.169 ms] [1.644725] multiplyCuda<<<1024, 256>>>
# [00000.172 ms] [1.644725] multiplyCuda<<<1024, 512>>>
# [00000.168 ms] [1.644725] multiplyCuda<<<1024, 1024>>>
# [00000.181 ms] [1.644725] multiplyCuda<<<2048, 32>>>
# [00000.171 ms] [1.644725] multiplyCuda<<<2048, 64>>>
# [00000.170 ms] [1.644725] multiplyCuda<<<2048, 128>>>
# [00000.170 ms] [1.644725] multiplyCuda<<<2048, 256>>>
# [00000.168 ms] [1.644725] multiplyCuda<<<2048, 512>>>
# [00000.162 ms] [1.644725] multiplyCuda<<<2048, 1024>>>
# [00000.186 ms] [1.644725] multiplyCuda<<<4096, 32>>>
# [00000.169 ms] [1.644725] multiplyCuda<<<4096, 64>>>
# [00000.172 ms] [1.644725] multiplyCuda<<<4096, 128>>>
# [00000.167 ms] [1.644725] multiplyCuda<<<4096, 256>>>
# [00000.168 ms] [1.644725] multiplyCuda<<<4096, 512>>>
# [00000.167 ms] [1.644725] multiplyCuda<<<4096, 1024>>>
# [00000.189 ms] [1.644725] multiplyCuda<<<8192, 32>>>
# [00000.171 ms] [1.644725] multiplyCuda<<<8192, 64>>>
# [00000.169 ms] [1.644725] multiplyCuda<<<8192, 128>>>
# [00000.166 ms] [1.644725] multiplyCuda<<<8192, 256>>>
# [00000.167 ms] [1.644725] multiplyCuda<<<8192, 512>>>
# [00000.168 ms] [1.644725] multiplyCuda<<<8192, 1024>>>
# [00000.181 ms] [1.644725] multiplyCuda<<<16384, 32>>>
# [00000.168 ms] [1.644725] multiplyCuda<<<16384, 64>>>
# [00000.167 ms] [1.644725] multiplyCuda<<<16384, 128>>>
# [00000.166 ms] [1.644725] multiplyCuda<<<16384, 256>>>
# [00000.167 ms] [1.644725] multiplyCuda<<<16384, 512>>>
# [00000.168 ms] [1.644725] multiplyCuda<<<16384, 1024>>>
# [00000.184 ms] [1.644725] multiplyCuda<<<32768, 32>>>
# [00000.168 ms] [1.644725] multiplyCuda<<<32768, 64>>>
# [00000.167 ms] [1.644725] multiplyCuda<<<32768, 128>>>
# [00000.166 ms] [1.644725] multiplyCuda<<<32768, 256>>>
# [00000.166 ms] [1.644725] multiplyCuda<<<32768, 512>>>
# [00000.169 ms] [1.644725] multiplyCuda<<<32768, 1024>>>
#
# ...
```

[![](https://i.imgur.com/bGUUPot.gif)][sheetp]
[![](https://i.imgur.com/eLQ7XpP.gif)][sheetp]

[![](https://i.imgur.com/IagoPuk.gif)][sheetp]
[![](https://i.imgur.com/4L394Vk.gif)][sheetp]

[![](https://i.imgur.com/tCUuW0a.gif)][sheetp]
[![](https://i.imgur.com/tZaV8K6.gif)][sheetp]

[![](https://i.imgur.com/U6jbPeH.gif)][sheetp]
[![](https://i.imgur.com/mpjbvkK.gif)][sheetp]

[![](https://i.imgur.com/TVSzgPr.png)][sheetp]
[![](https://i.imgur.com/edMTlIA.png)][sheetp]
[![](https://i.imgur.com/g5oxQ1H.png)][sheetp]
[![](https://i.imgur.com/1Jyepy2.png)][sheetp]

<br>
<br>


## References

- [CUDA by Example :: Jason Sanders, Edward Kandrot](https://www.slideshare.net/SubhajitSahu/cuda-by-example-notes)

<br>
<br>

[![](https://i.imgur.com/lRwvZLe.png)](https://www.youtube.com/watch?v=vTdodyhhjww)
[![DOI](https://zenodo.org/badge/375073607.svg)](https://zenodo.org/badge/latestdoi/375073607)

[Prof. Dip Sankar Banerjee]: https://sites.google.com/site/dipsankarban/
[Prof. Kishore Kothapalli]: https://cstar.iiit.ac.in/~kkishore/
[Nsight Compute]: https://developer.nvidia.com/nsight-compute
[charts]: https://photos.app.goo.gl/xorYb1MZSNqxUgNy7
[sheets]: https://docs.google.com/spreadsheets/d/1fWcVNQbANgiNepryktAsIWUHCNiAi-Yf1qQyiLsTJio/edit?usp=sharing
[sheetp]: https://docs.google.com/spreadsheets/d/e/2PACX-1vQ5RS676pMmWtXRj0AaPSkBDdFHZWTEDgyMJGDq2mdSz7GfWektVErY130Y84eTAxuCMDGogdvLEzyZ/pubhtml

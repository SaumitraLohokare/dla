# dla
Diffusion Limited Aggregation in C

## Build and Run
1. `make`
2. `./dla` or `./dla.exe` on Windows

> To edit the parameters for DLA, change the `#define`s in `main.c`.

## What is DLA?
In 1981, Thomas Witten and Leonard Sander introduced a concept called diffusion-limited aggregation. This process happens when particles move randomly through a medium and stick together when they come close enough. As they continue to join together, they create unique branching shapes known as Brownian trees, which have a fractal-like appearance.

<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/b/b8/DLA_Cluster.JPG/640px-DLA_Cluster.JPG" width=320>

## How does this DLA algorithm work?
To simulate diffusion-limited aggregation (DLA), we begin with a large canvas and place a single point. Then, we keep adding more points, moving them until they touch one of the existing points. However, this can be slow, especially at the beginning when there are very few points. To speed up the process, we start with a smaller canvas and fill it with 25% of the points we want. After that, we gradually increase the canvas size and fill it again with another 25% of points. We repeat this process for as many steps as needed. This method helps the points connect more quickly and reduces the overall time it takes for the simulation to run. By using this approach, we create the characteristic branching structures of DLA more efficiently.

## Generated Examples
<div style="display: flex; flex-direction: row;">
<img src="https://github.com/SaumitraLohokare/dla/blob/main/generated_images/1.png" width=200>
<img src="https://github.com/SaumitraLohokare/dla/blob/main/generated_images/2.png" width=200>
</div>

## Libraries Used
- [olive.c](https://github.com/tsoding/olive.c)
- [stb_image_write](https://github.com/nothings/stb/blob/master/stb_image_write.h)

## References Used
- Josh's Channel. [2024]. Better Mountain Generators That Aren't Perlin Noise or Erosion. Youtube. [https://youtu.be/gsJHzBTPG0Y?si=XsmrUwdWN12zGl9H]

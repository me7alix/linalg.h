# linalg.h

A lightweight, single-header linear algebra library written in C.  
It provides convenient vector types (`Vec2`, `Vec3`, `Vec4`) and a set of macros for common mathematical operations such as addition, subtraction, dot products, normalization, interpolation, and rotations.

## Features

- **Header-only** — just include `linalg.h` in your project.
- **Vector types**:
  - `Vec2` — 2D vector with `(x, y)`
  - `Vec3` — 3D vector with `(x, y, z)`
  - `Vec4` — 4D vector with `(x, y, z, w)`
- **Utility functions/macros**:
  - Squared values
  - Linear interpolation (`lerp`) and inverse interpolation (`ilerp`)
  - Vector addition, subtraction, dot product, length, normalization, distance
  - 2D rotation

## Usage

### Example: Vec2

```c
#include <stdio.h>
#include "linalg.h"

int main(void) {
    Vec2 a = {3.0f, 4.0f};
    Vec2 b = {1.0f, 2.0f};

    Vec2 sum = v2add(a, b);
    float dot = v2dot(a, b);
    float len = v2len(a);
    Vec2 norm = v2norm(a);

    printf("Sum: (%f, %f)\n", sum.x, sum.y);
    printf("Dot: %f\n", dot);
    printf("Length of a: %f\n", len);
    printf("Normalized a: (%f, %f)\n", norm.x, norm.y);

    return 0;
}
```

### Example: Rotation

```c
#include <stdio.h>
#include "linalg.h"

int main(void) {
    Vec3 dir = {1, 0, 0};
    vrot(dir.x, dir.z, PI / 3); // Rotate dir in XZ axis by 60 degrees

    printf("Rotated vector: (%f, %f, %f)\n", dir.x, dir.y, dir.z);
    return 0;
}
```

## API Reference

### Scalar helpers

* `v1sq(a)` — square of a
* `v1lerp(a, b, t)` — linear interpolation between `a` and `b`
* `v1ilerp(a, b, c)` — inverse lerp

### Vec2

* `v2add(a, b)` — add vectors
* `v2sub(a, b)` — subtract vectors
* `v2dot(a, b)` — dot product
* `v2len(a)` — length
* `v2norm(a)` — normalized vector
* `v2dist(a, b)` — distance
* `v2lerp(a, b, t)` — linear interpolation
* `v2ilerp(a, b, c)` — inverse interpolation

### Vec3

* `v3add(a, b)`
* `v3sub(a, b)`
* `v3dot(a, b)`
* `v3len(a)`
* `v3norm(a)`
* `v3dist(a, b)`
* `v3lerp(a, b, t)`
* `v3ilerp(a, b, c)`

### Vec4

* `v4add(a, b)`
* `v4sub(a, b)`
* `v4dot(a, b)`
* `v4len(a)`
* `v4norm(a)`
* `v4dist(a, b)`
* `v4lerp(a, b, t)`
* `v4ilerp(a, b, c)`

### Rotation

* `vrot(a, b, t)` — rotate a 2D vector `(a, b)` by angle `t` (radians)

## Notes

* This library is macro-based for **performance and inline expansion**.
* Normalization does **not** check for zero-length vectors — make sure your vector length is non-zero before normalizing.
* Some macros use **GNU statement expressions** (`({ ... })`) and may require GCC/Clang/TCC.

## License

MIT License. Free to use, modify, and distribute.

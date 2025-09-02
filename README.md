# linalg.h - Lightweight Vector Math Library for C

LinAlg is a single-header C library providing basic linear algebra operations for 2D, 3D, and 4D vectors. It includes common vector functions like addition, subtraction, dot product, normalization, distance, linear interpolation (lerp), inverse lerp, and a 2D rotation utility. All functions are implemented as inline functions for performance.

This library is designed to be simple, portable, and easy to integrate into projects without external dependencies beyond the standard math library.

## Features

- **Vector Types**:
  - `Vec2`: 2D vector (x, y)
  - `Vec3`: 3D vector (x, y, z)
  - `Vec4`: 4D vector (x, y, z, w)

- **Operations** (available for Vec2, Vec3, Vec4 where applicable):
  - Addition (`v2add`, `v3add`, `v4add`)
  - Subtraction (`v2sub`, `v3sub`, `v4sub`)
  - Dot product (`v2dot`, `v3dot`, `v4dot`)
  - Length/magnitude (`v2len`, `v3len`, `v4len`)
  - Normalization (`v2norm`, `v3norm`, `v4norm`)
  - Distance between vectors (`v2dist`, `v3dist`, `v4dist`)
  - Linear interpolation (lerp) (`v2lerp`, `v3lerp`, `v4lerp`)
  - Inverse linear interpolation (ilerp) (`v2ilerp`, `v3ilerp`, `v4ilerp`)

- **Scalar Helpers**:
  - Square (`v1sq`)
  - Lerp (`v1lerp`)
  - Inverse lerp (`v1ilerp`)

- **Rotation**:
  - `vrot`: In-place 2D rotation of two float components by an angle in radians.

- **Constants**:
  - `PI` defined as `3.14159265f` if not already present.

All functions are pure and do not modify input vectors unless specified (e.g., `vrot` modifies in-place).

## Installation

This is a single-header library. Simply copy `linalg.h` into your project.

To use it:
- Include `#include "linalg.h"` in your source files.
- In **exactly one** source file, define `LINALG_IMPLEMENTATION` before including the header to generate the function bodies.

Example:
```c
// In one .c file:
#define LINALG_IMPLEMENTATION
#include "linalg.h"

// In other .c files:
#include "linalg.h"
```

Link against the math library (`-lm` on Unix-like systems) since it uses `sqrtf`, `cosf`, and `sinf` from `<math.h>`.

## Usage

### Basic Example

```c
#include <stdio.h>
#define LINALG_IMPLEMENTATION  // Define in one file only
#include "linalg.h"

int main() {
    Vec2 a = {1.0f, 2.0f};
    Vec2 b = {3.0f, 4.0f};

    Vec2 sum = v2add(a, b);
    float dot = v2dot(a, b);
    float len = v2len(a);
    Vec2 norm = v2norm(a);

    printf("Sum: (%f, %f)\n", sum.x, sum.y);
    printf("Dot product: %f\n", dot);
    printf("Length of a: %f\n", len);
    printf("Normalized a: (%f, %f)\n", norm.x, norm.y);

    // Rotation example
    Vec3 dir = {1, 0, 0};
    vrot(dir.x, dir.z, PI / 3.0f);  // Rotate by 60 degrees in XZ axis
    printf("Rotated: (%f, %f, %f)\n", dir.x, dir.y, dir.z);

    return 0;
}
```

### Interpolation Example

```c
Vec3 start = {0.0f, 0.0f, 0.0f};
Vec3 end = {10.0f, 20.0f, 30.0f};
Vec3 interpolated = v3lerp(start, end, 0.5f);  // Midpoint
// interpolated = {5.0f, 10.0f, 15.0f}
```

## Building and Compiling

Compile with a C compiler, e.g.:
```
gcc -o example example.c -lm
```

Tested with GCC and Clang on C99 and later standards.

## Limitations

- No matrix operations (focus on vectors only).
- Floating-point only (uses `float`).
- No error handling for division by zero (e.g., in normalization if length is zero).
- Rotation is a simple 2D utility; for 3D/4D rotations, consider quaternions or matrices (not included).

## Contributing

Feel free to submit issues or pull requests for improvements, such as adding more operations or optimizations.

## License

This library is released into the public domain (Unlicense). You can use, modify, and distribute it freely without restrictions.

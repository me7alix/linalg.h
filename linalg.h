#ifndef LINALG_H_
#define LINALG_H_

#include <math.h>

#ifndef PI
#define PI 3.14159265f
#endif

typedef struct { float x, y;       } Vec2;
typedef struct { float x, y, z;    } Vec3;
typedef struct { float x, y, z, w; } Vec4;

#define v2(...) ((Vec2) { __VA_ARGS__ })
#define v3(...) ((Vec3) { __VA_ARGS__ })
#define v4(...) ((Vec4) { __VA_ARGS__ })

#define v1sq(a) ((a) * (a))
float v1lerp(float a, float b, float t);
float v1ilerp(float a, float b, float c);

Vec2 v2add(Vec2 a, Vec2 b);
Vec2 v2sub(Vec2 a, Vec2 b);
Vec2 v2scale(Vec3 a, float sc);
float v2dot(Vec2 a, Vec2 b);
float v2len(Vec2 a);
Vec2 v2norm(Vec2 a);
float v2dist(Vec2 a, Vec2 b);
Vec2 v2lerp(Vec2 a, Vec2 b, float t);
Vec2 v2ilerp(Vec2 a, Vec2 b, Vec2 c);

Vec3 v3add(Vec3 a, Vec3 b);
Vec3 v3sub(Vec3 a, Vec3 b);
Vec3 v3scale(Vec3 a, float sc);
float v3dot(Vec3 a, Vec3 b);
float v3len(Vec3 a);
Vec3 v3norm(Vec3 a);
float v3dist(Vec3 a, Vec3 b);
Vec3 v3lerp(Vec3 a, Vec3 b, float t);
Vec3 v3ilerp(Vec3 a, Vec3 b, Vec3 c);

Vec4 v4add(Vec4 a, Vec4 b);
Vec4 v4sub(Vec4 a, Vec4 b);
Vec4 v4scale(Vec4 a, float sc);
float v4dot(Vec4 a, Vec4 b);
float v4len(Vec4 a);
Vec4 v4norm(Vec4 a);
float v4dist(Vec4 a, Vec4 b);
Vec4 v4lerp(Vec4 a, Vec4 b, float t);
Vec4 v4ilerp(Vec4 a, Vec4 b, Vec4 c);

typedef float Mat4x4[16];
void m4x4add(Mat4x4 dst, Mat4x4 a, Mat4x4 b);
void m4x4dot(Mat4x4 dst, Mat4x4 a, Mat4x4 b);
void m4x4mult(Mat4x4 dst, float sc);
void m4x4copy(Mat4x4 dst, Mat4x4 src);

#define MAT_AT(m, r, c) m[(r) * 4 + (c)]

#define vrot(a, b, t) \
do { \
	float _vr_la = (a); \
	float _vr_lb = (b); \
	(a) = _vr_la * cosf(t) - _vr_lb * sinf(t); \
	(b) = _vr_la * sinf(t) + _vr_lb * cosf(t); \
} while(0)

#endif // LINALG_H_

#ifdef LINALG_IMPLEMENTATION

inline float v1lerp(float a, float b, float t) { return a + (b - a) * t; }
inline float v1ilerp(float a, float b, float c) { return (c - a) / (b - a); }

inline Vec2 v2add(Vec2 a, Vec2 b) { return (Vec2){a.x + b.x, a.y + b.y}; }
inline Vec2 v2sub(Vec2 a, Vec2 b) { return (Vec2){a.x - b.x, a.y - b.y}; }
inline Vec2 v2scale(Vec2 a, float sc) { return (Vec2){a.x * sc, a.y * sc}; }
inline float v2dot(Vec2 a, Vec2 b) { return a.x * b.x + a.y * b.y; }
inline float v2len(Vec2 a) { return sqrtf(v1sq(a.x) + v1sq(a.y)); }
inline Vec2 v2norm(Vec2 a) { float l = v2len(a); return (Vec2){a.x / l, a.y / l}; }
inline float v2dist(Vec2 a, Vec2 b) { return sqrtf(v1sq(a.x - b.x) + v1sq(a.y - b.y)); }
inline Vec2 v2lerp(Vec2 a, Vec2 b, float t) { return (Vec2){v1lerp(a.x, b.x, t), v1lerp(a.y, b.y, t)}; }
inline Vec2 v2ilerp(Vec2 a, Vec2 b, Vec2 c) { return (Vec2){v1ilerp(a.x, b.x, c.x), v1ilerp(a.y, b.y, c.y)}; }

inline Vec3 v3add(Vec3 a, Vec3 b) { return (Vec3){a.x + b.x, a.y + b.y, a.z + b.z}; }
inline Vec3 v3sub(Vec3 a, Vec3 b) { return (Vec3){a.x - b.x, a.y - b.y, a.z - b.z}; }
inline Vec3 v3scale(Vec3 a, float sc) { return (Vec3){a.x * sc, a.y * sc, a.z * sc}; }
inline float v3dot(Vec3 a, Vec3 b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
inline float v3len(Vec3 a) { return sqrtf(v1sq(a.x) + v1sq(a.y) + v1sq(a.z)); }
inline Vec3 v3norm(Vec3 a) { float l = v3len(a); return (Vec3){a.x / l, a.y / l, a.z / l}; }
inline float v3dist(Vec3 a, Vec3 b) { return sqrtf(v1sq(a.x - b.x) + v1sq(a.y - b.y) + v1sq(a.z - b.z)); }
inline Vec3 v3lerp(Vec3 a, Vec3 b, float t) { return (Vec3){v1lerp(a.x, b.x, t), v1lerp(a.y, b.y, t), v1lerp(a.z, b.z, t)}; }
inline Vec3 v3ilerp(Vec3 a, Vec3 b, Vec3 c) { return (Vec3){v1ilerp(a.x, b.x, c.x), v1ilerp(a.y, b.y, c.y), v1ilerp(a.z, b.z, c.z)}; }

inline Vec4 v4add(Vec4 a, Vec4 b) { return (Vec4){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w}; }
inline Vec4 v4sub(Vec4 a, Vec4 b) { return (Vec4){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w}; }
inline Vec4 v4scale(Vec4 a, float sc) { return (Vec4){a.x * sc, a.y * sc, a.z * sc, a.w * sc}; }
inline float v4dot(Vec4 a, Vec4 b) { return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w; }
inline float v4len(Vec4 a) { return sqrtf(v1sq(a.x) + v1sq(a.y) + v1sq(a.z) + v1sq(a.w)); }
inline Vec4 v4norm(Vec4 a) { float l = v4len(a); return (Vec4){a.x / l, a.y / l, a.z / l, a.w / l}; }
inline float v4dist(Vec4 a, Vec4 b) { return sqrtf(v1sq(a.x - b.x) + v1sq(a.y - b.y) + v1sq(a.z - b.z) + v1sq(a.w - b.w)); }
inline Vec4 v4lerp(Vec4 a, Vec4 b, float t) { return (Vec4){v1lerp(a.x, b.x, t), v1lerp(a.y, b.y, t), v1lerp(a.z, b.z, t), v1lerp(a.w, b.w, t)}; }
inline Vec4 v4ilerp(Vec4 a, Vec4 b, Vec4 c) { return (Vec4){v1ilerp(a.x, b.x, c.x), v1ilerp(a.y, b.y, c.y), v1ilerp(a.z, b.z, c.z), v1ilerp(a.w, b.w, c.w)}; }

inline void m4x4add(Mat4x4 dst, Mat4x4 a, Mat4x4 b) {
	for (size_t i = 0; i < 16; i++) {
		dst[i] = a[i] + b[i];
	}
}

inline void m4x4mult(Mat4x4 a, float sc) {
	for (size_t i = 0; i < 16; i++) {
		a[i] = sc * a[i];
	}
}

inline void m4x4dot(Mat4x4 dst, Mat4x4 a, Mat4x4 b) {
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; j++) {
			MAT_AT(dst, i, j) = 0;
			for (size_t k = 0; k < 4; k++) {
				MAT_AT(dst, i, j) += MAT_AT(a, i, k) * MAT_AT(a, k, j);
			}
		}
	}
}

inline void m4x4copy(Mat4x4 dst, Mat4x4 src) {
	for (size_t i = 0; i < 16; i++) {
		dst[i] = src[i];
	}
}

#endif // LINALG_IMPLEMENTATION

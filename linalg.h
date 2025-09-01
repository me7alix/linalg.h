#ifndef LINALG_H_
#define LINALG_H_

#include <math.h>

#ifndef PI
#define PI 3.14159265f
#endif //PI

typedef struct { float x, y;       } Vec2;
typedef struct { float x, y, z;    } Vec3;
typedef struct { float x, y, z, w; } Vec4;

#define v1sq(a) ((a) * (a))
#define v1lerp(a, b, t)  ((a) + ((b) - (a)) * (t))
#define v1ilerp(a, b, c) (((c) - (a)) / ((b) - (a)))

#define v2add(a, b) ((Vec2) {(a).x + (b).x, (a).y + (b).y})
#define v2sub(a, b) ((Vec2) {(a).x - (b).x, (a).y - (b).y})
#define v2dot(a, b) ((a).x * (b).x + (a).y * (b).y)
#define v2len(a) sqrtf(v1sq((a).x) + v1sq((a).y))
#define v2norm(a) ({float l = v2len(a); ((Vec2) {(a).x/l, (a).y/l});}) 
#define v2dist(a, b) sqrtf(v1sq((a).x-(b).x) + v1sq((a).y-(b).y))
#define v2lerp(a, b, t) ((Vec2) {v1lerp((a).x, (b).x, (t)), v1lerp((a).y, (b).y, (t))})
#define v2ilerp(a, b, c) ((Vec2) {v1ilerp((a).x, (b).x, (c).x), v1ilerp((a).y, (b).y, (c).y)})

#define v3add(a, b) ((Vec3) {(a).x + (b).x, (a).y + (b).y, (a).z + (b).z})
#define v3sub(a, b) ((Vec3) {(a).x - (b).x, (a).y - (b).y, (a).z - (b).z})
#define v3dot(a, b) ((a).x * (b).x + (a).y * (b).y + (a).z * (b).z)
#define v3len(a) sqrtf(v1sq((a).x) + v1sq((a).y) + v1sq((a).z))
#define v3norm(a) ({float l = v3len(a); ((Vec3) {(a).x/l, (a).y/l, (a).z/l});})
#define v3dist(a, b) sqrtf(v1sq((a).x-(b).x) + v1sq((a).y-(b).y) + v1sq((a).z-(b).z))
#define v3lerp(a, b, t) ((Vec3) {v1lerp((a).x, (b).x, (t)), v1lerp((a).y, (b).y, (t)), v1lerp((a).z, (b).z, (t))})
#define v3ilerp(a, b, c) ((Vec3) {v1ilerp((a).x, (b).x, (c).x), v1ilerp((a).y, (b).y, (c).y), v1ilerp((a).z, (b).z, (c).z)})

#define v4add(a, b) ((Vec4) {(a).x + (b).x, (a).y + (b).y, (a).z + (b).z, (a).w + (b).w})
#define v4sub(a, b) ((Vec4) {(a).x - (b).x, (a).y - (b).y, (a).z - (b).z, (a).w - (b).w})
#define v4dot(a, b) ((a).x * (b).x + (a).y * (b).y + (a).z * (b).z + (a).w * (b).w)
#define v4len(a) sqrtf(v1sq((a).x) + v1sq((a).y) + v1sq((a).z) + v1sq((a).w))
#define v4norm(a) ({float l = v4len(a); (Vec4) {(a).x/l, (a).y/l, (a).z/l, (a).w/l}})
#define v4dist(a, b) sqrtf(v1sq((a).x-(b).x) + v1sq((a).y-(b).y) + v1sq((a).z-(b).z) + v1sq((a).w-(b).w))
#define v4lerp(a, b, t) ((Vec4) {v1lerp((a).x, (b).x, (t)), v1lerp((a).y, (b).y, (t)), v1lerp((a).z, (b).z, (t)), v1lerp((a).w, (b).w, (t))})
#define v4ilerp(a, b, c) ((Vec4) {v1ilerp((a).x, (b).x, (c).x), v1ilerp((a).y, (b).y, (c).y), v1ilerp((a).z, (b).z, (c).z), v1ilerp((a).w, (b).w, (c).w)})

#define vrot(a, b, t) \
	do { \
		float _vr_la = (a); \
		float _vr_lb = (b); \
		(a) = _vr_la * cosf(t) - _vr_lb * sinf(t); \
		(b) = _vr_la * sinf(t) + _vr_lb * cosf(t); \
	} while (0)

#endif // LINALG_H_

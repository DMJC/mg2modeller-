#include "../include/nurbs.h"

void nurbs::generateMesh() {
	tessellate(tessellation_resolution);
}

void nurbs::tessellate(int resolution) {
	// NURBS tessellation: evaluate the surface at a grid of parameter values
	// and generate polygon mesh. Full implementation requires de Boor's algorithm.
	// For now, delegate to base class mesh generation from vertex/face lists.
	object::generateMesh();
}

void nurbs::setTessellationResolution(int res) {
	tessellation_resolution = res;
	mesh.markDirty();
}

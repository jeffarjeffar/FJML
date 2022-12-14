#include "layers.h"

namespace FJML {

namespace Layers {

layer_vals Layer::apply(const layer_vals& input) { return input; }

std::vector<layer_vals> Layer::apply(const std::vector<layer_vals>& input) { return input; }

std::vector<layer_vals> Layer::apply_grad(const std::vector<layer_vals>& input_vals,
										  const std::vector<layer_vals>& output_grad) {
	return output_grad;
}

void Layer::save(std::ofstream& file) {}

Layer* load(std::ifstream& file) {
	std::string type;
	file >> type;
	if (type == "Dense") {
		return new Layers::Dense(file);
	} else if (type == "Softmax") {
		return new Layers::Softmax;
	} else {
		std::cout << "Error: Unknown layer type: " << type << std::endl;
		return nullptr;
	}
}

} // namespace Layers

} // namespace FJML
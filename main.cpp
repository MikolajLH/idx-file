#include "idx_file.h"
#include <ranges>
#include <cassert>
#include <iterator>
#include <iostream>


char float_to_char(float f)
{
	if (f <= 0.30f)return char(219);
	if (f <= 0.50f)return char(178);
	if (f <= 0.70f)return char(177);
	if (f <= 0.90f)return char(176);
	return ' ';
}

auto& matrix_at(std::contiguous_iterator auto begin, size_t r, size_t c, size_t R, size_t C) {
	assert((r * C + c < R * C));
	return *(begin + r * C + c);
}

int main()
{
	auto images_file = IDX_File("MNIST_database/t10k-images.idx3-ubyte");
	auto labels_file = IDX_File("MNIST_database/t10k-labels.idx1-ubyte");

	static constexpr auto image_w = 28u;
	static constexpr auto image_h = 28u;

	const size_t n = 7;
	for (const auto& [image_begin, label] : 
			std::views::zip(
				images_file.data_uint8_t | std::views::stride(image_w * image_h),
				labels_file.data_uint8_t
			) | std::views::take(n)) {

		for (int i = 0; i < image_h; ++i) {
			for (int j = 0; j < image_w; ++j) {
				float v = (float)matrix_at(&image_begin, i, j, image_h, image_w) / 255.f;
				std::cout << float_to_char(1.f - v);
			}
			std::cout << '\n';
		}

		std::cout << "Label: " << (int)label << "\n";
		std::cout << "----------------------------\n";
	}


	return 0;
}

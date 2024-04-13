[**MNIST** database and **IDX** format specification](http://yann.lecun.com/exdb/mnist/)
---

After loading the file

```c++
auto labels_file = IDX_File("MNIST_database/t10k-labels.idx1-ubyte");
```

the data is inside one of the vector depending of the data type. The other vectors are empty
```c++
class IDX_File
{
	public:
		IDX_File(std::string_view path) ;

		std::string_view type{};
		std::vector<std::uint8_t> data_uint8_t{};
		std::vector<std::int8_t> data_int8_t{};
		std::vector<std::int16_t> data_int16_t{};
		std::vector<std::int32_t> data_int32_t{};
		std::vector<float> data_float{};
		std::vector<double> data_double{};
      ...
};
```
so to use it just access the adequate vector
```c++
auto labels = std::move(labels_file.data_uint8_t);
for(auto label : labels){
      std::cout << (int)label << "\n";
}
```

## Example `main.cpp` output
```
path: MNIST_database/t10k-images.idx3-ubyte
data type: 8 -> unsigned byte -> std::uint8_t
number of dimensions: 3
dim 1: 10000
dim 2: 28
dim 3: 28
data_size: 7840000
File ended as expected, loaded 7840000 chunks of data


path: MNIST_database/t10k-labels.idx1-ubyte
data type: 8 -> unsigned byte -> std::uint8_t
number of dimensions: 1
dim 1: 10000
data_size: 10000
File ended as expected, loaded 10000 chunks of data



      ▒█▓▓░░
      ██████████████▓░
      ░▒░▒▓██████████▓
            ░ ░░░░ ██▒
                  ▒██
                  ██▒
                 ▓██░
                ░██░
                ▓██
                ██░
               ▒██
              ░██░
              ██▓
             ███░
            ░██▒
           ░██▒
           ▓██░
          ░███░
          ▒███░
          ▒██

Label: 7

----------------------------

          ▒▒▓██▓▒
         ▓███████░
        ▓████▓▓██▒
       ░███░   ██▓
       ▒██    ▒██░
        ░     ███░
             ▒███
            ░███░
            ▓██▓
           ▓██▓
           ███░
          ███▓
         ▒███
         ███▓
        ▓██▓
        ███
        ███░         ░▓▓▓▓
        ████████▓▓▓███████▒
        ▓██████████████▓▒▒░
         ▒▒▒▒▓███▓▒▒░

Label: 2

----------------------------
```

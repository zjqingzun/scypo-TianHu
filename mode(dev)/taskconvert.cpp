#include "taskconvert.h"



// 
void __convertPython() {
    py::scoped_interpreter guard{};

    try {
        py::module_ sys = py::module_::import("sys");

        // Thêm thư mục chứa controller.py vào sys.path
        sys.attr("path").attr("append")("mode/services/task/py");

        // Import module controller
        py::module_ pyctlr = py::module_::import("controller");

        // Gọi hàm process_data(42)
        py::object result = pyctlr.attr("process_data")(42);

        // Ép kiểu kết quả sang int
        int output = result.cast<int>();

        std::cout << "Kết quả từ Python: " << output << std::endl;
    } catch (const py::error_already_set& e) {
        std::cerr << "Python Error: " << e.what() << std::endl;
    }
}

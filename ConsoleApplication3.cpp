#include <iostream>
#include <fdeep/fdeep.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <filesystem>
#include <string>
#include <stack>
#include <exception>
using namespace stdext;
namespace fs = std :: filesystem;
int main()
{


    std::string test_image_folder_path = "C:\testdata"; // path to folder containing test images
    const auto mymodel = fdeep::load_model("C:\frugally-deep-master\keras_export\CatDogNew.json"); // load the converted model
    for (const auto& entry : fs::directory_iterator(test_image_folder_path)) {
        try
        {
            std::string image_path = entry.path().string(); // get images path one by one
            const cv::Mat image = cv::imread(image_path, cv::IMREAD_GRAYSCALE);  // read the image in single channel grayscale mode 

            cv::Mat resizedImg;
            cv::resize(image, resizedImg, cv::Size(128, 128)); // resize image to the 128x128 (Model input dimension)
            imshow("Display Window", resizedImg); // just show the image

            // convert cv::MAT to fdeep::tensor
            const auto input = fdeep::tensor_from_bytes(resizedImg.ptr(),
                static_cast<std::size_t>(resizedImg.rows),
                static_cast<std::size_t>(resizedImg.cols),
                static_cast<std::size_t>(resizedImg.channels()),
                0.0f, 1.0f);

            auto result = mymodel.predict({ input }); // predict the image's label and ouput a 1x2 tensor containing each class probability
            std::cout << fdeep::show_tensors(result) << std::endl; // print the tensor
            cv::waitKey();
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }


}
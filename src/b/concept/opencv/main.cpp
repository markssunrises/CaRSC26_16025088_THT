#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // 1. Muat gambar
    cv::Mat image = cv::imread("input.jpg");

    if (image.empty()) {
        std::cout << "Gagal memuat gambar" << std::endl;
        return -1;
    }

    // 2. Transformasi efek sketsa/tepi (Canny)
    cv::Mat gray, blurred, edges;
    
    // Ubah ke Grayscale
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    
    // Mengurangi noise dengan Gaussian Blur
    cv::GaussianBlur(gray, blurred, cv::Size(5, 5), 1.5);
    
    // Deteksi Tepi (Canny)
    cv::Canny(blurred, edges, 100, 200);

    // 3. Simpan hasil transformasi
    cv::imwrite("output_sketsa.jpg", edges);

    std::cout << "Transformasi selesai" << std::endl;

    return 0;
}
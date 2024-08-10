#include <graphics.h>
#include <iostream>

/**
 * 绘图设备的封装类
 */
class Device {
public:
	//构造函数
	Device (const int& width, const int& height)
		: width_(width), height_(height), maximum_pixel_(width_ * height_) {
		//初始化窗口
		handle_ = initgraph(width_, height_);
		if (handle_ != nullptr) {
			//获取缓冲区
			buffer_ = GetImageBuffer();
			//开始批量绘制
			BeginBatchDraw();
		} else {
			std::clog << "\rDevice Creating Failure : No widget has been created."
					  << std::flush;
			exit(-1);
		}
	}
	//析构函数
	~Device() {
		//结束批量绘制
		EndBatchDraw();
		//关闭窗口
		closegraph();
	}
	//获取像素
	DWORD& At(const size_t& x, const size_t& y) const {
		if (y * width_ + x >= maximum_pixel_) {
			std::clog << "\rDevice Failure : Subscript out of range." << std::flush;
		}
		return buffer_[y * width_ + x];
	}
	//刷新
	static void Flush() {
		//刷新批量绘制
		FlushBatchDraw();
	}

private:
	HWND   handle_; //句柄,用于标识图形设备的窗口
	DWORD* buffer_; //缓冲区
	int	   width_;  //宽度
	int	   height_; //高度
	int	   maximum_pixel_; //最大像素
};
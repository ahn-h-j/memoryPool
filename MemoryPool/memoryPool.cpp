#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>

class MemoryPool {
public:
	MemoryPool(size_t blockSize, size_t numBlocks) : blockSize_(blockSize) {
		buffer_ = new char[blockSize_ * numBlocks];
		for (size_t i = 0; i < numBlocks; ++i) {
			freeList_.push_back(buffer_ + i * blockSize_);
		}
	}

	~MemoryPool() {
		delete[] buffer_;
	}

	void* allocate() {
		if (freeList_.empty()) {
			return nullptr;
		}
		void* ptr = freeList_.back();
		freeList_.pop_back();
		return ptr;
	}

	void deallocate(void* ptr) {
		freeList_.push_back(static_cast<char*>(ptr));
	}

private:
	size_t blockSize_;
	char* buffer_;
	std::vector<void*> freeList_;
};

int main() {
	std::string a = "hhh";
	std::cout << a.size() << std::endl;
	size_t byteSize = a.size();
	MemoryPool pool(100, 10);
	char* bufferTest1 = static_cast<char*>(pool.allocate());
	strcpy(bufferTest1, "Hello buffer1");
	std::cout << "Size of bufferTest1 : " << sizeof(*bufferTest1)*strlen(bufferTest1) << " bytes"<<" buffer text : "<< bufferTest1 << std::endl;

	/*char* bufferTest2 = static_cast<char*>(pool.allocate());
	strcpy(bufferTest2, "Hello buffer2");
	std::cout << bufferTest2 << std::endl;
	
	char* bufferTest3 = static_cast<char*>(pool.allocate());
	strcpy(bufferTest3, "Hello buffer3");
	std::cout << bufferTest3 << std::endl;
	
	char* bufferTest4 = static_cast<char*>(pool.allocate());
	strcpy(bufferTest4, "Hello buffer4");
	std::cout << bufferTest4 << std::endl;
	
	char* bufferTest5 = static_cast<char*>(pool.allocate());
	strcpy(bufferTest5, "Hello buffer5");
	std::cout << bufferTest5 << std::endl;
	
	char* bufferTest6 = static_cast<char*>(pool.allocate());
	strcpy(bufferTest6, "Hello buffer6");
	std::cout << bufferTest6 << std::endl;
	
	char* bufferTest7 = static_cast<char*>(pool.allocate());
	strcpy(bufferTest7, "Hello buffer7");
	std::cout << bufferTest7 << std::endl;
	
	char* bufferTest8 = static_cast<char*>(pool.allocate());
	strcpy(bufferTest8, "Hello buffer8");
	std::cout << bufferTest8 << std::endl;
	
	char* bufferTest9 = static_cast<char*>(pool.allocate());
	strcpy(bufferTest9, "Hello buffer9");
	std::cout << bufferTest9 << std::endl;
	
	char* bufferTest10 = static_cast<char*>(pool.allocate());
	strcpy(bufferTest10, "Hello buffer10");
	std::cout << bufferTest10 << std::endl;
	
	pool.deallocate(bufferTest1);

	std::cout << bufferTest1 << std::endl;
	char* bufferTest11 = static_cast<char*>(pool.allocate());
	strcpy(bufferTest11, "Hello buffer11");
	std::cout << bufferTest11 << std::endl;
	pool.deallocate(bufferTest11);

	char* bufferTest12 = static_cast<char*>(pool.allocate());
	strcpy(bufferTest12, "Hello buffer12");
	std::cout << bufferTest12 << std::endl;
	pool.deallocate(bufferTest12);

	char* bufferTest13 = static_cast<char*>(pool.allocate());
	strcpy(bufferTest13, "Hello buffer13");
	std::cout << bufferTest13 << std::endl;
	pool.deallocate(bufferTest13);

	char* bufferTest14 = static_cast<char*>(pool.allocate());
	strcpy(bufferTest14, "Hello buffer14");
	std::cout << bufferTest14 << std::endl;*/


}
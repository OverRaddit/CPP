#include <iostream>
#include <fstream> // 파일입출력
#include <string>

// 생성하고 제출할것.
int main(int argc, char *argv[])
{
	if (argc != 4)
		return (-1);

	// 예상치못한 입력, 오류를 처리.
	//
	//

	std::string filename(argv[1]);
	std::string s1(argv[2]);
	std::string s2(argv[3]);
	std::ifstream readFile(filename);
	std::ofstream writeFile(filename + ".replace");
	std::string buf;

	// OPEN
	if (!readFile.is_open()){
		std::cout << "FILE OPEN ERROR" << std::endl;
		return (-1);
	}
	// READ
	while(!readFile.eof())
	{
		std::string str;
		getline(readFile, str);
		buf += str;
		buf += '\n';
	}
	buf = buf.substr(0, buf.length() - 1);	// last \n delete

	// make filename.replace
	if(!writeFile.is_open()){
		std::cout << "FILE OPEN ERROR" << std::endl;
		return (-1);
	}

	// [Replace] find->substr
	int idx;
	while(1)
	{
		if ((idx = buf.find(s1)) == (int)std::string::npos)
			break;
		// find s1
		std::string front = buf.substr(0, idx);
		std::string back = buf.substr(idx + s1.length(), buf.length() - (idx + s1.length()));
		buf = front + s2 + back;
	}
	// buf를 filename.replace에 출력
	writeFile << buf;	//writeFile.write(buf.c_str(), buf.length());

	// close
	readFile.close();
	writeFile.close();
}
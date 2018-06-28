/******************************************************************************* 
 *  @file      util.cpp 2017\5\11 17:01:27 $
 *  @author    df
 *  @brief     
 ******************************************************************************/

#include "util.h"
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> 
#include <iostream>

#include "../log.h"
/******************************************************************************/


/******************************************************************************/

std::string util::itoa(int i, int rdx)
{
    char _rs[100] = {0};
	snprintf(_rs, sizeof(_rs), "%d", i);
    //itoa(i, _rs, rdx);

    return std::string(_rs);
}

std::string util::read_file(std::string file) {
	std::string file_content;
	const char* fileName = file.c_str();
	printf("file name : %s \n", file.c_str());
	int fd = open(fileName, O_RDWR);
	struct stat buf={0};
	int status = stat(fileName, &buf);
	if (status == -1) {
		printf("read status error\n");
		return file_content;
	}
	int fileSize = buf.st_size;
	printf("file_content lengthdsize : %d \n", fileSize);
	char fileBuf[fileSize];
	int readSize = read(fd, fileBuf, fileSize);
	if (readSize != fileSize) {
		printf(ERR, "read file error\n");
		return file_content;
	}
	file_content = std::string(fileBuf, fileSize);
	const char* file_c = file_content.c_str();
	printf("file_content length : %d \n", file_content.length());
	return file_content;
}
/*
std::string util::read_file(std::string file)
{
    std::string file_content;
	LOG(ERR, "file name : %s ", file.c_str());
    char *file_content_buf = nullptr;
    try{
        std::ifstream file_;
        file_.open(file, std::ios_base::binary);
        if (!file_.is_open())
        {
            return file_content;
        }
        file_.seekg(0, std::ios::end);
        std::streamoff file_size = file_.tellg();
        file_.seekg(0);
        file_content_buf = new char[(unsigned int)file_size];
        file_.read(file_content_buf, file_size);
		LOG(ERR, "file_content length  size : %d ", (int)file_size);
        file_content = std::string(file_content_buf, (unsigned int)file_size);
        file_.close();
        delete[]file_content_buf;
        file_content_buf = nullptr;
    }
    catch (...){
        if (!file_content_buf){
            delete[]file_content_buf;
        }
    }
	const char* file_c = file_content.c_str();
	for (int i = 0; i < 52; i++) {
		LOG(ERR, "file_c char : %x ", *(file_c + i));
	}
	LOG(ERR, "file_content length : %d ", file_content.length());
    return file_content;
}
*/
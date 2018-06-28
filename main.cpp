#include <stdio.h>
#include <fstream>
#include <getopt.h>
#include "Core/elf_header.h"
#include "fix/section_fix.h"
#include <string.h> 
#include <stdio.h>
#include "util/util.h"
#include "log.h"
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> 
#include <iostream>

std::string source, output;

const char* short_options = "hdm:s:o:";
const struct option long_options[] = {
        {"help", 0, NULL, 'h'},
        {"debug", 0, NULL, 'd'},
        {"memso", 1, NULL, 'm'},
        {"source", 1, NULL, 's'},
        {"output", 1, NULL, 'o'},
        {nullptr, 0, nullptr, 0}
};


void print_useage(){
    printf("Usage: ./elf32fixer <option -s><input file>  <option -o><output file>\n");
}

void buidSection() {
	section_fix fixer_;
	printf("\t[+] start fix source \n");
	const char* sChar = source.c_str();
	char* pc = new char[100];
	strcpy(pc, sChar);
	std::string filetest = std::string(sChar);
	if (!fixer_.fix(source, pc)){
		printf("\t[-]elf file section build fail\n");
	}
	else{
		//std::string fixed_name_ = file_name + std::string(".fixed");
		if (!fixer_.save_as(output)){
			printf("\t[-]save fixed elf file fail\n");
		}
		printf("\t[+]fixed file => %s\n", output.c_str());
		printf("\t[+]elf file section build success!!!!!!!!!!!!!!!\n");
	}
}

int main(int argc, char* argv[]) {
	int c;
	if (argc != 5) {
		print_useage();
		return -1;
	}
	while((c = getopt_long(argc, argv, short_options, long_options, nullptr)) != -1) {
		switch(c) {
			case 's':
				source = optarg;
                break;
			case 'o':
				output = optarg;
                break;
			default:
				break;
		}
	}
	
	printf("\t[+] source file : %s , output file : %s \n", source.c_str(), output.c_str());
	if ((source.length() != 0) && (output.length() != 0)) {
		buidSection();
	} else {
		print_useage;
		return -1;
	}
}










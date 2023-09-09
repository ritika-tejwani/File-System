#pragma once
#include <vector> 
#include <string>
class AbstractFileVisitor;

enum success_or_failure {Success, append_not_supported, read_error, error_notXorspace, error_size_mismatch, write_invalid, failure_mapInsertion, error_nullptr, user_quit, input_not_oneWord, command_notFound, failure_addFile, command_failed, error_fileAlreadyExists, error_notTextorImageFile, error_noFileFound, error_fileNotOpen, error_fileIsOpen, error_fileDoesNotExist, cat_command_failure, display_command_error, copy_error, wrong_password, wrong_num_commands
};

// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary

class AbstractFile {
public:
    virtual std::vector<char> read() = 0;
    virtual int write(std::vector<char>) = 0;
    virtual int append(std::vector<char>) = 0;
    virtual unsigned int getSize() = 0;
    virtual std::string getName() = 0;
    virtual ~AbstractFile() = default;
    virtual void accept(AbstractFileVisitor* file) = 0;
    virtual AbstractFile* clone(std::string) = 0;
};
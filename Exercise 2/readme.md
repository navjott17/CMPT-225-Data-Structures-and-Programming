# Exercise 2

In this exercise you have minimal instructions. You should try to be independent and make your own reasonable assumptions as needed.

Write a complete C++ program that reads a text file that is supposed to have two columns: the first one is a list of student names and the second column is a list of double numbers from 0 to 100. Your program is supposed to write an addition line at the beginning of the text file saying: "The average of all the numbers is ...". You should predict all the exceptional cases that might lead to runtime error and provide handlers for them.

Example of the file content:

Allen 65

Bob  87

Su  79

Raj 76

Yunfei  90

Jenn  93

Alex  66

Ahmed  82

Fatima 88

You are supposed to have one function for reading the file, one function for calculating the average, and one function for writing the line on the file.

Your program is supposed to have a class named Students with appropriate attributes and methods. You are supposed to incorporate modularity and separate classes into cpp and header files.

Your program is supposed to have exception class(es).

In addition to the exceptions that you throw yourself, your program is supposed to handle at least one of the standard exception from the following list as well:

## Class hierarchy and Description

exception

bad_alloc: Thrown by new, an allocation request fails.

bad_cast: Thrown by dynamic_cast whenfailed cast to a reference type.

bad_exception: Thrown when an exception doesn't match any catch clause.

The logical errors are normally caused by programmer mistakes.

logic_error: As the base class for all exceptions thrown to report errors presumably detectable before the program executes, such as violations of logical preconditions.

domain_error: As the base class for all exceptions thrown to report a domain error.

invalid_argument: As the base class for all exceptions thrown to report an invalid argument.

length_error: As the base class for all exceptions thrown to report an attempt to generate an object too long to be specified.

out_of_range: As the base class for all exceptions thrown to report an argument that is out of its valid range.

The run-time errors normally occur because of mistakes in either the library functions or in the run-time system

runtime_error: As the base class for all exceptions thrown to report errors presumably detectable only when the program executes.

overflow_error: As the base class for all exceptions thrown to report an arithmetic overflow.

range_error: As the base class for all exceptions thrown to report a range error.

underflow_error: As the base class for all exceptions thrown to report an arithmetic underflow.

ios_base::failure: The member class serves as the base class for all exceptions thrown by the member function clear() in template class basic_ios.

Your program should incorporate inheritance.

You should include all the required libraries and namespaces.

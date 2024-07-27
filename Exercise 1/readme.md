# Exercise 1
In this exercise you are to implement the basic structure of a class (related to the as yet unpublished assignment 1) such that – even though the class methods are not implemented – it will still compile and run. There is a discussion at the end of this document that explains the purpose of this exercise.

## Requirements
Write the class definition of the Sequence class in a file named Sequence.h. Your class definition should contain the prototypes of the public methods described below. It should not have any private methods or attributes

Write stubs for each of the public methods in a file named Sequence.cpp – which should include Sequence.h. The stubs for the default constructor, insert and clear methods should be empty and the stubs for size and stdDeviation should return zero.
Sequence Class

## Class Description

Your class should be named Sequence and should have the following public methods:

default constructor (i.e. with no parameters)

insert – has a single double parameter

clear – empties the sequence

size – returns an integer equal to the number of items stored in the sequence

stdDeviation – returns a double equal to the standard deviation of the values in the sequence – note the camelCase name

## Notes

The calling object should be made constant for any method where the calling object's attribute values should not change

Method parameters and return values are noted (and highlighted) in the method descriptions – you must not add additional parameters to the methods; if the method description does not mention a parameter it does not have one, similarly if no return value is mentioned the method is void (or a constructor or destructor). Methods must be given the same names as shown above.

As described above under requirements your methods should be stubs – either empty if void or returning a default value otherwise. You should not implement their described functionality.

There is no copy constructor, overloaded assignment operator or destructor specified for this class, which you would normally expect. This is intended to reduce the amount of work for this first exercise.

## Class Files

Your class should consist of a header file called Sequence.h that contains the class definition and an implementation file called Sequence.cpp that contains the method stubs.

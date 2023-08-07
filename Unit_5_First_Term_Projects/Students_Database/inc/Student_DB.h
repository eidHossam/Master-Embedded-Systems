/**
 * @file Student_DB.h
 * 
 * @brief this file is the API for the Student
 * database module.  
 * 
 * @author Hossam_Eid (eidhossam7@gmail.com)
 * 
 * @date 06-08-2023
 * 
 * @version 1.0
 */

#ifndef STUDENT_DB_H_
#define STUDENT_DB_H_

#include "../inc/FIFO_Buff.h"



void add_student_file();
void add_student_manually();
void find_roll();
void find_fName();
void find_students_inCourse();
void total_students();
void delete_student();
void update_student();
void show_students();

#endif /*StUDENT_DB_H_*/
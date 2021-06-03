//==============================================
// Name:           Abdalla Aden
// Student Number: 021720057
// Email:          aaaden1@myseneca.ca
// Section:        NDD
// Date:           Jun 01 2021
//==============================================
// Workshop 02 Part 1
//==============================================
#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   bool read(char name[]);
   bool read(int& empNo);
   bool read(double& salary);

 

}
#endif //SDDS_FILE_H_

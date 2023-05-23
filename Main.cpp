#include <iostream>
#include <string.h>
#include <iomanip>
#include "ListCustomers.cpp"

using namespace std;

class Main
{
    public:
		// Nhap lua chon theo menu de thuc hien
        void executeByMenu()
		{
			readFilePatientDetail();
			if (numPatientDetail == 0) {
				cout << "[] - the database is empty" << endl;
				exit(1);
			}
			readFileSymptom();
			if (numSymptom == 0) {
				cout << "Unable to recommend COVID Test – required data missing" << endl;
				exit(1);
			}
			readFileLocation();

			int choose;
			do
			{
				cout << "\n ====================== Recommend the COVID Test =====================" << endl;
				cout << " | 1- Enter your detail for COVID-Test Recommendation                |" << endl;
				cout << " | 2- Submit Your Covid test status & Update the Location database   |" << endl;
				cout << " | 3- Display the Updated Location (High Risk for COVID)             |" << endl;
				cout << " | 4- Update COVID Patient Details           			     |" << endl;
				cout << " | 5- Display the COVID Positive Patient Detail                      |" << endl;
				cout << " | 6- Quit                       		   		     |" << endl;
				cout << " =====================================================================" << endl;
        	    cout << "Enter choose: "; cin >> choose;

        	    switch(choose)
        	    {
        	    	case 1:
        	    		{
							int patientID;
							string name, dOB, address, phoneNumber, lastOverseasTravel, symptoms = "", visitedLocation = "", dateTime;
							do{
								cout << "Enter patient id: "; cin >> patientID;
							} while(checkPatientID(patientID));
							cin.ignore();
							cout << "Enter name: "; getline(cin, name);
							cout << "Enter date of birth: "; getline(cin, dOB);
							cout << "Enter address: "; getline(cin, address);
							cout << "Enter phone number: "; getline(cin, phoneNumber);
							cout << "Enter last overseas travel (Yes or No): "; getline(cin, lastOverseasTravel);
							if (lastOverseasTravel == "Yes") {
								cout << "Enter date time: "; getline(cin, dateTime);
							}
							for (int i = 0; i < numLocation; i++) {
								cout << listLocation[i].getLocationID() << ". " << listLocation[i].getLocation() << endl;
							}
							cout << "Select id of visited location: "; getline(cin, visitedLocation);
							for (int i = 0; i < numSymptom; i++) {
								cout << listSymptom[i].getSymptomID() << ". " << listSymptom[i].getName() << endl;
							}
							cout << "Select id of symptoms: "; getline(cin, symptoms);
							PatientDetail temp(patientID, name, dOB, address, phoneNumber, lastOverseasTravel, symptoms, visitedLocation, dateTime);
							listPatientDetail[numPatientDetail++] = temp;
							writeFilePatientDetail();
							cout << recommendCOVIDTest(visitedLocation, symptoms) << endl;
        	    			break;
						}
					case 2:
						{
							int patientID;
							do{
								cout << "Enter patient id: "; cin >> patientID;
							} while(!checkPatientID(patientID));
							cin.ignore();
							string covidTest;
							cout << "Enter result of test covid (Positive or Negative): "; getline(cin, covidTest);
							if (covidTest == "Positive") {
								int numVisitedLocation = 0;
								string visitedLocation[100];
								string listLocationID = "";
								cout << "Enter number of visited location: "; cin >> numVisitedLocation;
								cin.ignore();
								for (int i = 1; i <= numVisitedLocation; i++) {
									cout << "Enter visited location " << i << ": "; getline(cin, visitedLocation[i]);
									listLocation[numLocation].setLocationID(numLocation + 1);
									listLocation[numLocation].setLocation(visitedLocation[i]);
									numLocation++;
									writeFileLocation();
									listLocationID += to_string(numLocation) + " ";
								}
								for (int i = 0; i < numPatientDetail; i++) {
									if (listPatientDetail[i].getPatientID() == patientID) {
										listPatientDetail[i].setCovidTest(covidTest);
										listPatientDetail[i].setVisitedLocation(listLocationID);
										writeFilePatientDetail();
									}
								}
							}
							break;
						}                  				
					case 3:
					    {
							cout << "====================== THE LOCATION FOR HIGH-RISK LOCATION===========================" << endl;
							cout << "Location ID" << "		Location" << endl;
					    	for (int i = 0; i < numLocation; i++) {
								cout << listLocation[i].getLocationID() << "		" << listLocation[i].getLocation() << endl;
							}
					    	break;
						}					
                    case 4:
						{
							int patientID;
							do{
								cout << "Enter patient id: "; cin >> patientID;
							} while(!checkPatientIDPositive(patientID));
							cin.ignore();
							string status;
							cout << "Enter status of patient (Cured or Dead): "; getline(cin, status);
							
							for (int i = 0; i < numPatientDetail; i++) {
								if (listPatientDetail[i].getPatientID() == patientID) {
									if (status == "Cured") {
										listPatientDetail[i].setCovidTest("Negative");
										listPatientDetail[i].setStatus("Alive");
									}
									else {
										listPatientDetail[i].setStatus("Dead");
									}
									
								}
							}
							
							writeFilePatientDetail();
							break;
						}
                    case 5:
                        {
							cout << "====================== THE COVID POSITIVE PATIENTS DETAIL===========================" << endl;
							for (int i = 0; i < numPatientDetail; i++) {
								if (listPatientDetail[i].getCovidTest() == "Positive") {
									cout << "Patient ID: " << listPatientDetail[i].getPatientID() << endl;
									cout << "Visited Location: " << endl << getLocation(listPatientDetail[i].getVisitedLocation());
									cout << "Last Overseas Travel: " << listPatientDetail[i].getLastOverseasTravel() << endl;
									cout << "Date time: " << listPatientDetail[i].getDateTime() << endl;
									cout << "Symptom: " << endl << getSymptom(listPatientDetail[i].getSymptoms()) << endl;
								}
							}
                            break;
                        }
					case 6:
					    {
					    	cout << "Goodbye" << endl;
                            exit(1);
						}	
                    default :
                        {
                            cout << "Unknown selection, please try again" << endl;
                        }
				}
			}
			while(choose != 6);
		}
};
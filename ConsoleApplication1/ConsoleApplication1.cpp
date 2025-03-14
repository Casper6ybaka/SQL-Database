#include "pch.h"
#include <iostream>
using namespace System::Data::SqlClient;
using namespace std;
using namespace System;

int main() {
    while (1) {

    }

    // WRITE
    try {
        String^ connectionstring = "Data Source=SENDHELPPLS\\SQLEXPRESS;Initial Catalog=NomminNoms;Integrated Security=True;Encrypt=False";
        SqlConnection^ con = gcnew SqlConnection(connectionstring);
        con->Open();
        String^ sqlquery = "INSERT INTO Users (Name, Age) VALUES ('Gilbert', 33);";
        SqlCommand^ cmd = gcnew SqlCommand(sqlquery, con);
        cmd->ExecuteNonQuery();
        con->Close();
    }
    catch (Exception^ ex)
    {
        std::cout << "ERRRR" << std::endl;
        throw ex;
    }


    // READ
    try {
        String^ connectionstring = "Data Source=SENDHELPPLS\\SQLEXPRESS;Initial Catalog=NomminNoms;Integrated Security=True;Encrypt=False";
        SqlConnection^ con = gcnew SqlConnection(connectionstring);
        con->Open();
        String^ sqlquery = "SELECT * FROM Users;";
        SqlCommand^ cmd = gcnew SqlCommand(sqlquery, con);
        SqlDataReader^ dr = cmd->ExecuteReader();
        while (dr->Read()) {
            Console::WriteLine("ID {0}:\n  -Name: {1} \n  -Age: {2}", dr["ID"], dr["Name"], dr["Age"]);
        }

        con->Close();
    }
    catch (Exception^ ex)
    {
        cout << "ERRRR" << endl;
        throw ex;
    }

    return 0;
}

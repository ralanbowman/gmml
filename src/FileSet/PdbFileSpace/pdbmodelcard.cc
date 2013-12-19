#include "../../../includes/FileSet/PdbFileSpace/pdbmodel.hpp"
#include "../../../includes/FileSet/PdbFileSpace/pdbmodelcard.hpp"

using namespace std;
using namespace PdbFileSpace;

//////////////////////////////////////////////////////////
//                       CONSTRUCTOR                    //
//////////////////////////////////////////////////////////
PdbModelCard::PdbModelCard() {}

//////////////////////////////////////////////////////////
//                         ACCESSOR                     //
//////////////////////////////////////////////////////////

string PdbModelCard::GetRecordName(){
    return record_name_;
}

PdbModelCard::PdbModelMap PdbModelCard::GetModels(){
    return models_;
}

//////////////////////////////////////////////////////////
//                       MUTATOR                        //
//////////////////////////////////////////////////////////

void PdbModelCard::SetRecordName(const string record_name){
    record_name_ = record_name;
}

void PdbModelCard::SetModels(PdbModelMap models){
    models_ = models;
}

//////////////////////////////////////////////////////////
//                        FUNCTIONS                     //
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
//                      DISPLAY FUNCTION                //
//////////////////////////////////////////////////////////


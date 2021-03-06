#include "../../../includes/InputSet/PdbFileSpace/pdblinkcard.hpp"
#include "../../../includes/InputSet/PdbFileSpace/pdblink.hpp"
#include "../../../includes/utils.hpp"

using namespace std;
using namespace PdbFileSpace;
using namespace gmml;

//////////////////////////////////////////////////////////
//                       CONSTRUCTOR                    //
//////////////////////////////////////////////////////////
PdbLinkCard::PdbLinkCard() {}

PdbLinkCard::PdbLinkCard(stringstream &stream_block)
{
    string line;
    bool is_record_name_set = false;
    getline(stream_block, line);
    string temp = line;
    while (!Trim(temp).empty())
    {
        if(!is_record_name_set){
            record_name_ = line.substr(0,6);
            Trim(record_name_);
            is_record_name_set=true;
        }

        PdbLink* link = new PdbLink(line);
        AddResidueLink(link);
        getline(stream_block, line);
        temp = line;
    }
}

//////////////////////////////////////////////////////////
//                         ACCESSOR                     //
//////////////////////////////////////////////////////////

string PdbLinkCard::GetRecordName(){
    return record_name_;
}

PdbLinkCard::LinkVector PdbLinkCard::GetResidueLinks(){
    return residue_links_;
}

//////////////////////////////////////////////////////////
//                       MUTATOR                        //
//////////////////////////////////////////////////////////

void PdbLinkCard::SetRecordName(string record_name){
    record_name_ = record_name;
}

void PdbLinkCard::SetResidueLinks(LinkVector residue_links){
    residue_links_.clear();
    for(LinkVector::iterator it = residue_links.begin(); it != residue_links.end(); it++)
    {
        residue_links_.push_back(*it);
    }
}

void PdbLinkCard::AddResidueLink(PdbLink *residue_link)
{
    residue_links_.push_back(residue_link);
}

//////////////////////////////////////////////////////////
//                        FUNCTIONS                     //
//////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////
//                      DISPLAY FUNCTION                //
//////////////////////////////////////////////////////////
void PdbLinkCard::Print(ostream &out)
{
    out << "Record Name: " << record_name_ << endl <<
           "================== Residue Links ================" << endl;
    for(PdbLinkCard::LinkVector::iterator it = residue_links_.begin(); it != residue_links_.end(); it++)
    {
        (*it)->Print(out);
        out << endl;
    }
    out << endl;
}

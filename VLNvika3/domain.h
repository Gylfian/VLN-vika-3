#ifndef DOMAIN_H
#define DOMAIN_H
#include <algorithm>
#include "data.h"

class Domain
{
public:

    /*
     * Name: Domain
     * Parameter/s: None
     * Description: Default constructor for Domain class
     * Usage:
     *
     */
    Domain();

    /*
     * Name: search
     * Parameter/s: vector<CScientist> &cSciList, CScientist cSci
     * Description: Controller for searching within list from database.
     * Usage: search(list, searchfilter)
     * Output/Return: List with applied filters.
     */

    void search(vector<CScientist> &cSciList, CScientist cSci);

    void search(vector<Computer> &cComList, Computer cCom);

    /*
     * Name: findScientist / findComputer
     * Parameter/s: CScientist cSci / Computer cCom
     * Description: Finds scientist or computer based on full information without id.
     * Usage: findScientist(cSci)
     * Output/Return: Completed instance of cSci, if information is valid.
     */

    CScientist findScientist(CScientist cSci);

    Computer findComputer(Computer cCom);

    /*
     * Name: findRelation
     * Parameter/s: string filter
     * Description: Finds either a scientist name or a computer based on filter.
     * Usage: findRelation("ada");
     * Output/Return: Finds anything including 'ada' in connection list.
     */

    vector<Relation> findRelation(string filter);

    /*
     * Name: findInactiveScientist / findInactiveComputer
     * Parameter/s: CScientist cSci / Computer cCom
     * Description: Lists everyone that is inactive (deleted).
     * Usage: findInactiveScientists(cSci / cCom)
     * Output/Return: Finds inactive instance based on the parameter instance.
     */

    CScientist findInactiveScientist(CScientist cSci);

    Computer findInactiveComputer(Computer cCom);

    /*
     * Name: findConnectionId
     * Parameter/s: string scientist, string computer
     * Description: Finds a connection based on names of connection.
     * Usage:findConnectionId("Blaise Pascal", "Pascaline");
     * Output/Return: Returns ID of specific connection.
     */

    int findConnectionId(string scientist, string computer);

    /*
     * Name: sortBy
     * Parameter/s: vector<CScientist> &cSciList or vector<Computer> &, int child, int child2
     * Description: Controller for sort decisions.
     * Usage: sortBy(cSciList, 1, 1)
     * Output/Return: Sorted scientist list by name, ascending.
     */

    void sortBy(vector<CScientist> &cSciList, char child, char child2);

    void sortBy(vector<Computer> &cComList, char child, char child2);

    void changeRelation(int sid);

    /*
     * Name: restoreEntry
     * Parameter/s: vector<CScientist> &cSciList
     * Description: Updates restore entry.
     * Usage: restoreEntry(cSciList)
     * Output/Return: ...
     */

    void restoreEntry(vector<CScientist> &cSciList);

    void restoreEntry(vector<Computer> &cSciList);

    /*
     * Name: updateEntrySci
     * Parameter/s: string sid
     * Description: Updates delete state.
     * Usage: updateEntrySci(id)
     * Output/Return: ...
    */

    void updateEntrySci(string sid);

    void updateEntryCom(string sid);

    void editEntry(string id);

    /*
     * Name: addEntry
     * Parameter/s: CScientist cSci or Computer cSci
     * Description: Adds an entry to database.
     * Usage: addEntry(cSci);
     * (void)Output/Return: element deleted from database.
     */
    void addEntry(CScientist cSci);
    void addEntry(Computer cSci);

    /*
     * Name: normalizeName
     * Parameter/s: string &name
     * Description: Fixes names that are badly input
     * Usage: normalizeName("jÓn bAlduRSsOn")
     * (str)Output/Return: Jón Baldursson
     */
    bool normalizeName(string &name);

    /*
     * Name: convertToInt
     * Description: Converts string to an integer
     * Usage: convertToInt("53")
     * Output/Return: 53, in integer.
     */
    int convertToInt(string str);

    /*
     * Name: checkStrInput
     * Parameter/s: string str
     * Description: Verifies string input
     * Usage: checkStrInput(str)
     * Output/Return: Returns whether string is valid or not.
     */
    int checkStrInput(string str);

    /*
     * Name: createRelation
     * Parameter/s: string str
     * Description: Creates a relation.
     * Usage: createRelation("1", "5")
     * Output/Return: 1 and 5 are connected.
     */

    void getRelationList(vector<Relation> &cRelList, int active);

    /*
     * Name: editEntry
     * Parameter/s: Computer cCom or CScientist cSci
     * Description: Updates an entry by id
     * Usage: editEntry(cSci)
     * Output/Return:
     */
    void editEntry(Computer cCom);
    void editEntry(CScientist cSci);

    /*
     * Name: addRelation
     * Parameter/s: Computer cCom and CScientist cSci
     * Description: Creates a relation between the two parameters.
     * Usage: addRelation(cSci, cCom)
     * Output/Return: Establishes a connection between cSci and cCom.
     */
    void addRelation(CScientist cSci, Computer cCom);

    /*
     * Name: removeRelations
     * Parameter/s: int id
     * Description: Deletes a relation by id
     * Usage: addRelation(5)
     * Output/Return: Deletes relation from the parameter, in this case id = 5.
     */
    void removeRelations(int id);

private:
    Data data;

    /*
     * Name: charToInt
     * Parameter/s: char chr
     * Description: Converts char to integer
     * Usage: charToInt('5')
     * Output/Return: 5 in integer.
     */
    int charToInt(char chr);

    /*
     * Name: get functions
     * Parameter/s: vector<CScientist> &cSciList or vector<Computer> &cComList, char child2
     * Description: Gets list, sort.
     * Usage: getName(cSciList, 2);
     * Output/Return: ...
     */
    void getName(vector<CScientist> &cSciList, char child2);
    void getGender(vector<CScientist> &cSciList, char child2);
    void getYear(vector<CScientist> &cSciList, char child2);
    void getYearDeath(vector<CScientist> &cSciList, char child2);
    void getId(vector<CScientist> &cSciList, char child2);
    void getActive(vector<CScientist> &cSciList);
    void getComName(vector<Computer> &cComList, char child2);
    void getComYear(vector<Computer> &cComList, char child2);
    void getComType(vector<Computer> &cComList, char child2);
    void getComBuilt(vector<Computer> &cComList, char child2);
    void getComId(vector<Computer> &cComList, char child2);
    void getComActive(vector<Computer> &cComList);
};

#endif // DOMAIN_H

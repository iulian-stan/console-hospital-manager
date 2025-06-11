#include "menu.h"
#include "list.h"
#include "appointment.h"
#include "surgery.h"

#ifndef _ACTIONS_H
#define _ACTIONS_H

/**
 * Display application description action
 */
class Description : public Action {
public:
    Description(char *name);
    void executeAction();
};

/**
 * Add a new person to the list action
 */
class AddPersonAction : public Action {
protected:
    List *list;
    Person *person;
public:
    AddPersonAction(char *name, List *&persons);
    virtual void executeAction() = 0;
};

/**
 * Add a new doctor action
 */
class AddDoctorAction : public AddPersonAction {
public:
    AddDoctorAction(char *name, List *&doctors);
    void executeAction();
};

/**
 * Add a new nurse action
 */
class AddNurseAction : public AddPersonAction {
public:
    AddNurseAction(char *name, List *&nurses);
    void executeAction();
};

/**
 * Add a new inpatient action
 */
class AddInpatientAction : public AddPersonAction {
public:
    AddInpatientAction(char *name, List *&inpatients);
    void executeAction();
};

/**
 * Add a new outpatient action
 */
class AddOutpatientAction : public AddPersonAction {
public:
    AddOutpatientAction(char *name, List *&outpatients);
    void executeAction();
};

/**
 * Change nurse status to doctor
 */
class PromoteNurseToDoctorAction : public Action {
private:
    List *nurses , *doctors;
public:
    PromoteNurseToDoctorAction(char *name, List *&nurses, List *&doctors);
    void executeAction();
};

/**
 * Chanage outpatient status to inpatient action
 */
class AdmitOutpatientAction : public Action {
private:
    List *outpatients , *inpatients;
public:
    AdmitOutpatientAction(char *name, List *&outpatients, List *&inpatients);
    void executeAction();
};

/**
 * Chanage inpatient status to outpatient action
 */
class DischargeInpatientAction : public Action {
private:
    List *inpatients , *outpatients;
public:
    DischargeInpatientAction(char *name, List *&inpatients, List *&outpatients);
    void executeAction();
};

/**
 * Print a list of persons action
 */
class PrintListAction : public Action {
private:
    List *list;
public:
    PrintListAction(char *name, List *list);
    void executeAction();
};

/**
 * Print a list of persons action
 */
class PrintListsAction : public Action {
private:
    List *list1, *list2;
public:
    PrintListsAction(char *name, List *list1, List *list2);
    void executeAction();
};

/**
 * Remove a person from a list
 */
class RemovePersonAction : public Action {
private:
    List *list;
public:
    RemovePersonAction(char *name, List *&list);
    void executeAction();
};

/**
 * Add appointment action
 */
class AddAppointmentAction : public Action {
private:
    AppointmentList *appointments;
    List *doctors, *outpatients;
public:
    AddAppointmentAction(char *name, AppointmentList *&appointments, List *doctors, List *outpatients);
    void executeAction();
};

/**
 * Print all appointments by a doctor action
 */
class PrintDoctorAppointmentsAction : public Action {
private:
    AppointmentList *appointments;
    List *doctors;
public:
    PrintDoctorAppointmentsAction(char *name, AppointmentList *appointments, List *doctors);
    void executeAction();
};

/**
 * Print all appointments by an outpatient action
 */
class ProintOutpatientAppointmentsAction : public Action {
private:
    AppointmentList *appointments;
    List *outpatients;
public:
    ProintOutpatientAppointmentsAction(char *name, AppointmentList *appointments, List *outpatients);
    void executeAction();
};

/**
 * Print all appointments action
 */
class PrintAppointmentsAction : public Action {
private:
    AppointmentList *appointments;
public:
    PrintAppointmentsAction(char *name, AppointmentList *appointments);
    void executeAction();
};

/**
 * Add surgery action
 */
class AddSurgeryAction : public Action {
private:
    SurgeryList *surgeries;
    List *doctors, *nurses, *inpatients;
public:
    AddSurgeryAction(char *name, SurgeryList *surgeries, List *doctors, List *nurses, List *inpatients);
    void executeAction();
};

/**
 * Print all surgeries by a doctor action
 */
class PrintDoctorSurgeriesAction : public Action {
private:
    SurgeryList *surgeries;
    List *doctors;
public:
    PrintDoctorSurgeriesAction(char *name, SurgeryList *surgeries, List *doctors);
    void executeAction();
};

/**
 * Print all surgeries by a nurse action
 */
class PrintNurseSurgeriesAction : public Action {
private:
    SurgeryList *surgeries;
    List *nurses;
public:
    PrintNurseSurgeriesAction(char *name, SurgeryList *surgeries, List *nurses);
    void executeAction();
};

/**
 * Print all surgeries by an inpatient action
 */
class PrintInpatientSurgeriesAction : public Action {
private:
    SurgeryList *surgeries;
    List *inpatients;
public:
    PrintInpatientSurgeriesAction(char *name, SurgeryList *surgeries, List *inpatients);
    void executeAction();
};

/**
 * Print all surgeries action
 */
class PrintSurgeriesAction : public Action {
private:
    SurgeryList *surgeries;
public:
    PrintSurgeriesAction(char *name, SurgeryList *surgeries);
    void executeAction();
};

/**
 * Write data to a file action
 */
class FileWriteAction : public Action {
    List *doctors, *nurses, *inpatients, *outpatients;
public:
    FileWriteAction(char *name, List *doctors, List *nurses, List *inpatients, List *outpatients);
    void executeAction();
};

/**
 * Read data from a file action
 */
class FileReadAction : public Action {
    List *doctors, *nurses, *inpatients, *outpatients;
public:
    FileReadAction(char *name, List *doctors, List *nurses, List *inpatients, List *outpatients);
    void executeAction();
};

#endif
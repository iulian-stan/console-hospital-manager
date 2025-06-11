#include <iostream>
#include <string>
#include <iomanip>
#include "global.h"
#include "menu.h"
#include "actions.h"
using namespace std;

int main() {
    Menu *menu = new Menu("Hospital");

    List *doctors = new List();
    List *nurses = new List();
    List *inpatients = new List();
    List *outpatients = new List();

    AppointmentList *appointments = new AppointmentList();
    SurgeryList *surgeries = new SurgeryList();

    Menu *submenuStaff = new Menu("Staff");
    menu->addItem(submenuStaff);

    submenuStaff->addItem(new PrintListsAction("Print staff", doctors, nurses));

    Menu *submenuDoctor = new Menu("Doctor");
    submenuStaff->addItem(submenuDoctor);
    submenuDoctor->addItem(new AddDoctorAction("Add doctor", doctors));
    submenuDoctor->addItem(new RemovePersonAction("Dismiss doctor", doctors));
    submenuDoctor->addItem(new PrintListAction("Print doctors", doctors));

    Menu *submenuNurse = new Menu("Nurse medical");
    submenuStaff->addItem(submenuNurse);
    submenuNurse->addItem(new AddNurseAction("Add nurse", nurses));
    submenuNurse->addItem(new PromoteNurseToDoctorAction("Promote nurse", nurses, doctors));
    submenuNurse->addItem(new RemovePersonAction("Dismiss nurse", nurses));
    submenuNurse->addItem(new PrintListAction("Print nurses", nurses));

    Menu *submenuPatients = new Menu("Patients");
    menu->addItem(submenuPatients);

    submenuPatients->addItem(new PrintListsAction("Print outpatients", inpatients, outpatients));

    Menu *submenuInpatients = new Menu("Inpatients");
    submenuPatients->addItem(submenuInpatients);
    submenuInpatients->addItem(new AddInpatientAction("Add internat", inpatients));
    submenuInpatients->addItem(new DischargeInpatientAction("Discharge internat", outpatients, inpatients));
    submenuInpatients->addItem(new PrintListAction("Print inpatients", inpatients));

    Menu *submenuOutpatients = new Menu("Outpatients");
    submenuPatients->addItem(submenuOutpatients);
    submenuOutpatients->addItem(new AddOutpatientAction("Add outpatient", outpatients));
    submenuOutpatients->addItem(new RemovePersonAction("Dismiss outpatient", outpatients));
    submenuOutpatients->addItem(new AdmitOutpatientAction("Internare outpatient", outpatients, inpatients));
    submenuOutpatients->addItem(new PrintListAction("Print outpatients", outpatients));

    Menu *submenuAction = new Menu("Action");
    menu->addItem(submenuAction);

    Menu *submenuAppointment = new Menu("Appointment");
    submenuAction->addItem(submenuAppointment);
    submenuAppointment->addItem(new AddAppointmentAction("Add appointment", appointments, doctors, outpatients));
    submenuAppointment->addItem(new PrintDoctorAppointmentsAction("Appointments by a doctor", appointments, doctors));
    submenuAppointment->addItem(new ProintOutpatientAppointmentsAction("Appointments by an outpatient", appointments, outpatients));
    submenuAppointment->addItem(new PrintAppointmentsAction("Print appointments", appointments));

    Menu *submenuSurgery = new Menu("Action");
    submenuAction->addItem(submenuSurgery);
    submenuSurgery->addItem(new AddSurgeryAction("Schedule a surgery", surgeries, doctors, nurses, inpatients));
    submenuSurgery->addItem(new PrintDoctorSurgeriesAction("Surgeries by a doctor", surgeries, doctors));
    submenuSurgery->addItem(new PrintNurseSurgeriesAction("Surgeries by a nurse", surgeries, nurses));
    submenuSurgery->addItem(new PrintInpatientSurgeriesAction("Surgeries by a inpatient", surgeries, inpatients));
    submenuSurgery->addItem(new PrintSurgeriesAction("Print surgeries", surgeries));

    Menu *submenuFile = new Menu("File IO");
    menu->addItem(submenuFile);
    submenuFile->addItem(new FileReadAction("Read", doctors, nurses, inpatients, outpatients));
    submenuFile->addItem(new FileWriteAction("Write", doctors, nurses, inpatients, outpatients));

    menu->addItem(new Description("About the program"));

    menu->execute();

    delete surgeries;
    delete appointments;

    delete doctors;
    delete nurses;
    delete inpatients;
    delete outpatients;

    delete menu;

    cout << endl << endl << "The end." << endl;

    pause();
    return 0;
}
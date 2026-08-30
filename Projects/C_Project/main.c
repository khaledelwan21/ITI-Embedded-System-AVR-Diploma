/* ============================================================
   Clinic Management System
   - Admin Mode & User Mode
   - Patients stored using a LINKED LIST
   - 5 fixed appointment slots (array)
   ============================================================ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ADMIN_PASSWORD "1234"
#define MAX_TRIES 3
#define NUM_SLOTS 5

/* ---------------- Patient Node (Linked List) ---------------- */
typedef struct Patient {
    char name[50];
    int age;
    char gender[10];
    int id;
    struct Patient *next;
} Patient;

Patient *head = NULL;  /* head of the linked list */

/* ---------------- Appointment Slot ---------------- */
typedef struct {
    char time[20];
    int isBooked;   /* 0 = free, 1 = booked */
    int patientID;  /* valid only if isBooked = 1 */
} Slot;

Slot slots[NUM_SLOTS] = {
    {"2:00 PM - 2:30 PM", 0, -1},
    {"2:30 PM - 3:00 PM", 0, -1},
    {"3:00 PM - 3:30 PM", 0, -1},
    {"3:30 PM - 4:00 PM", 0, -1},
    {"4:30 PM - 5:00 PM", 0, -1}
};

/* ================= Linked List Helper Functions ================= */

/* Search patient by ID, return pointer or NULL */
Patient* findPatient(int id) {
    Patient *temp = head;
    while (temp != NULL) {
        if (temp->id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

/* Add new patient to linked list (at the end) */
void addPatient() {
    int id, age;
    char name[50], gender[10];

    printf("Enter Patient ID: ");
    scanf("%d", &id);

    if (findPatient(id) != NULL) {
        printf(">> Error: ID already exists!\n");
        return;
    }

    printf("Enter Name: ");
    scanf("%s", name);
    printf("Enter Age: ");
    scanf("%d", &age);
    printf("Enter Gender: ");
    scanf("%s", gender);

    Patient *newNode = (Patient*) malloc(sizeof(Patient));
    strcpy(newNode->name, name);
    newNode->age = age;
    strcpy(newNode->gender, gender);
    newNode->id = id;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Patient *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf(">> Patient added successfully!\n");
}

/* Edit existing patient */
void editPatient() {
    int id;
    printf("Enter Patient ID to edit: ");
    scanf("%d", &id);

    Patient *p = findPatient(id);
    if (p == NULL) {
        printf(">> Error: Incorrect ID!\n");
        return;
    }

    printf("Enter new Name: ");
    scanf("%s", p->name);
    printf("Enter new Age: ");
    scanf("%d", &p->age);
    printf("Enter new Gender: ");
    scanf("%s", p->gender);

    printf(">> Patient updated successfully!\n");
}

/* View patient info (used in User Mode) */
void viewPatient() {
    int id;
    printf("Enter Patient ID: ");
    scanf("%d", &id);

    Patient *p = findPatient(id);
    if (p == NULL) {
        printf(">> Error: Patient not found!\n");
        return;
    }

    printf("\n--- Patient Info ---\n");
    printf("ID     : %d\n", p->id);
    printf("Name   : %s\n", p->name);
    printf("Age    : %d\n", p->age);
    printf("Gender : %s\n", p->gender);
}

/* ================= Slot / Reservation Functions ================= */

void showAvailableSlots() {
    printf("\n--- Available Slots ---\n");
    int any = 0;
    for (int i = 0; i < NUM_SLOTS; i++) {
        if (!slots[i].isBooked) {
            printf("%d) %s\n", i + 1, slots[i].time);
            any = 1;
        }
    }
    if (!any)
        printf("No available slots right now.\n");
}

void reserveSlot() {
    int id, choice;

    printf("Enter Patient ID: ");
    scanf("%d", &id);

    if (findPatient(id) == NULL) {
        printf(">> Error: Patient ID does not exist!\n");
        return;
    }

    showAvailableSlots();
    printf("Enter slot number to reserve (0 to cancel): ");
    scanf("%d", &choice);

    if (choice == 0) return;

    if (choice < 1 || choice > NUM_SLOTS) {
        printf(">> Invalid slot number!\n");
        return;
    }

    if (slots[choice - 1].isBooked) {
        printf(">> Error: This slot is already booked!\n");
        return;
    }

    slots[choice - 1].isBooked = 1;
    slots[choice - 1].patientID = id;
    printf(">> Slot reserved successfully!\n");
}

void cancelReservation() {
    int id;
    printf("Enter Patient ID to cancel reservation: ");
    scanf("%d", &id);

    for (int i = 0; i < NUM_SLOTS; i++) {
        if (slots[i].isBooked && slots[i].patientID == id) {
            slots[i].isBooked = 0;
            slots[i].patientID = -1;
            printf(">> Reservation cancelled successfully!\n");
            return;
        }
    }
    printf(">> Error: No reservation found for this Patient ID!\n");
}

void viewTodayReservations() {
    printf("\n--- Today's Reservations ---\n");
    int any = 0;
    for (int i = 0; i < NUM_SLOTS; i++) {
        if (slots[i].isBooked) {
            printf("%s  ->  Patient ID: %d\n", slots[i].time, slots[i].patientID);
            any = 1;
        }
    }
    if (!any)
        printf("No reservations yet today.\n");
}

/* ================= Menus ================= */

void adminMenu() {
    int choice;
    do {
        printf("\n===== ADMIN MENU =====\n");
        printf("1. Add New Patient\n");
        printf("2. Edit Patient Record\n");
        printf("3. Reserve a Slot\n");
        printf("4. Cancel Reservation\n");
        printf("5. Logout\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addPatient(); break;
            case 2: editPatient(); break;
            case 3: reserveSlot(); break;
            case 4: cancelReservation(); break;
            case 5: printf("Logging out...\n"); break;
            default: printf(">> Invalid choice!\n");
        }
    } while (choice != 5);
}

int adminLogin() {
    char password[20];
    int tries = 0;

    while (tries < MAX_TRIES) {
        printf("Enter Admin Password: ");
        scanf("%s", password);

        if (strcmp(password, ADMIN_PASSWORD) == 0) {
            printf(">> Login successful!\n");
            return 1;
        } else {
            tries++;
            printf(">> Incorrect password! Attempts left: %d\n", MAX_TRIES - tries);
        }
    }

    printf(">> Too many failed attempts. Closing system.\n");
    return 0;
}

void userMenu() {
    int choice;
    do {
        printf("\n===== USER MENU =====\n");
        printf("1. View Patient Record\n");
        printf("2. View Today's Reservations\n");
        printf("3. Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: viewPatient(); break;
            case 2: viewTodayReservations(); break;
            case 3: printf("Returning...\n"); break;
            default: printf(">> Invalid choice!\n");
        }
    } while (choice != 3);
}

/* Free linked list memory before exiting */
void freeAllPatients() {
    Patient *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/* ================= Main ================= */

int main() {
    int mode;

    do {
        printf("\n===== CLINIC MANAGEMENT SYSTEM =====\n");
        printf("1. Admin Mode\n");
        printf("2. User Mode\n");
        printf("3. Exit\n");
        printf("Choose mode: ");
        scanf("%d", &mode);

        switch (mode) {
            case 1:
                if (adminLogin()) {
                    adminMenu();
                } else {
                    freeAllPatients();
                    return 0; /* close system after 3 failed tries */
                }
                break;
            case 2:
                userMenu();
                break;
            case 3:
                printf("Exiting system...\n");
                break;
            default:
                printf(">> Invalid choice!\n");
        }
    } while (mode != 3);

    freeAllPatients();
    return 0;
}
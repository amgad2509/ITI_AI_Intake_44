import time
from datetime import datetime
from validate_Input import validate_date
from save_User_Data_Project import save_project_data

def create_project(user_id):
    title = input("Please Enter project title: ")
    details = input("Please Enter project details: ")
    target_amount = int(input("Please Enter target You Want : "))

    start_date = input("Please Enter start date in this Format NOT anything else (Year-Month-Day): ")
    while not validate_date(start_date):
        print("NOT VALID Format, Please use this format NOT anything else (Year-Month-Day) ")
        start_date = input("Please Enter start date NOT anything else (Year-Month-Day): ")

    end_date = input("Please Enter end date, please use this Format NOT anything else (Year-Month-Day): ")
    while not validate_date(end_date):
        print("NOT VALID Format Please use this Format NOT anything else (Year-Month-Day)")
        end_date = input("Please Enter end date use this Format NOT anything else (Year-Month-Day): ")

    project_id = round(time.time())
    project_data = f"user_id : {user_id} : project_id : {project_id} : title : {title} : details : {details} : target_amount : {target_amount} : start_date : {start_date} : end_date : {end_date}"
    save_project_data(project_data)

def edit_project(user_id):
    projects = []
    with open("projects_data.txt", "r") as file:
        for line in file:
            project_data = line.strip().split(" : ")
            projects.append(project_data)

    if not projects:
        print("No projects found For Everyone..")
        return

    user_projects = [project for project in projects if int(project[1]) == user_id]

    if not user_projects:
        print("You don't have any projects to edit")
        return

    print("\nYour Projects:")
    for project in user_projects:
        print(project)

    project_id = input("Enter the project ID you want to edit: ")
    edited_projects = []

    for project in projects:
        if project[3] == project_id and int(project[1]) == user_id:
            print("Press (t) ==> IF you want to Change Title\nPress (d) ==> IF you want to Change Details\nPress (a) ==> IF you want to Change new_target_amount\nPress (s) ==> IF you want to Change Start_Date\nPress (e) ==> IF you want to Change End_Date\nPress anything else to terminate edit Mode")
            while True:
                charr = input()
                if charr.lower() == 't':
                    new_title = input("Enter new project title: ")
                    project[5] = new_title
                elif charr.lower() == 'd':
                    new_details = input("Enter new project details: ")
                    project[7] = new_details
                elif charr.lower() == 'a':
                    new_target_amount = int(input("Enter new target amount: "))
                    project[9] = new_target_amount
                elif charr.lower() == 's':
                    new_start_date = input("Enter new start date, please use this Format NOT anything else (Year-Month-Day): ")
                    while not validate_date(new_start_date):
                        print("NOT Valid, please use this Format NOT anything else (Year-Month-Day): ")
                        new_start_date = input("Enter new start date, please use this Format NOT anything else (Year-Month-Day): ")
                    project[11] = new_start_date
                elif charr.lower() == 'e':
                    new_end_date = input("Enter new end date, please use this Format NOT anything else (Year-Month-Day): ")
                    while not validate_date(new_end_date):
                        print("NOT Valid format, please use this Format NOT anything else (Year-Month-Day): ")
                        new_end_date = input("Enter new end date, please use this Format NOT anything else (Year-Month-Day): ")
                    project[13] = new_end_date
                else:
                    print("Thank you, Your data has been updated....")
                    edited_projects.append(project)
                    break
        else:
            edited_projects.append(project)

    with open("projects_data.txt", "w") as file:
        for p in edited_projects:
            file.write(" : ".join(map(str, p)) + "\n")

    print("Project edited, Thank You")

def delete_project(user_id):
    projects = []
    with open("projects_data.txt", "r") as file:
        for line in file:
            project_data = line.strip().split(" : ")
            projects.append(project_data)

    if not projects:
        print("No projects found for Anyone")
        return

    user_projects = [project for project in projects if int(project[1]) == user_id]

    if not user_projects:
        print("You don't have any projects to delete")
        return

    print("\nYour Projects:")
    for project in user_projects:
        print(project)

    project_id = input("Enter the project ID you want to delete: ")

    finaal_proj = [project for project in projects if project[3] != project_id or int(project[1]) != user_id]

    if len(finaal_proj) == len(projects):
        print("NOT Valid Project ID , No project deleted")
        return
    with open("projects_data.txt", "w") as file:
        for project in finaal_proj:
            file.write(" : ".join(map(str, project)) + "\n")

    print("Project deleted, Thank you")

def search_project_by_date():
    new_start_date = input("Enter start date You Want to search for , please use this Format NOT anything else (Year-Month-Day): ")
    while not validate_date(new_start_date):
        print("NOT Valid, please use this Format NOT anything else (Year-Month-Day): ")
        new_start_date = input("Enter new start date, please use this Format NOT anything else (Year-Month-Day): ")
    projects = []
    with open("projects_data.txt", "r") as file:
        for line in file:
            project_data = line.strip().split(" : ")
            start_date = project_data[11]
            #end_date = project_data[13]

            if start_date == new_start_date:
                projects.append(project_data)

    if not projects:
        print("No projects found for the given date")
    else:
        print("\nProjects found for the given date:")
        for project in projects:
            print(project)

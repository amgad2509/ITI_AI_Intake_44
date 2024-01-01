from creat_Project_Operations import create_project,edit_project,delete_project,search_project_by_date
from view_RegiserUsers_projects import view_projects
from validate_Input import validate_date
def user_Choice(user_id):
    if user_id is not None:
            while True:
                print("\n\n1. Create Project\n2. View Projects\n3. Edit Project\n4. Delete Project\n5. Search Project by Date\n6. Exit(LOGOUT)")
                choice = input("Enter your choice: ")
                if choice == "1":
                    create_project(user_id)
                elif choice == "2":
                    view_projects()
                elif choice == "3":
                    edit_project(user_id)
                elif choice == "4":
                    delete_project(user_id)
                elif choice == "5":
                    search_project_by_date()
                else:
                    print("Thank You , You are Logged Out NOW .... ")
                    break
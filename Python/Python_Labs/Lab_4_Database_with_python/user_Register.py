import time
from datetime import datetime
from getpass import getpass
from validate_Input import validate_email,validate_phone
from view_RegiserUsers_projects import view_registered_users
from save_User_Data_Project import save_user_data
def get_password():
    return getpass("Please Enter Password: ")

def register():
    num_users = int(input("Enter the number of users to register:"))

    for i in range(num_users):
        first_name = input("Please Enter First Name: ")
        last_name = input("Please Enter Last Name: ")
        email = input("Please Enter Email: ")
        while not validate_email(email):
            print("Invalid email format")
            email = input("Enter Email Again: ")

        password = get_password()

        confirm_password = get_password()
        while password != confirm_password:
            print("Passwords do not match, try again")
            password = get_password()
            confirm_password = get_password()

        mobile_phone = input("Enter Mobile Phone:")
        while not validate_phone(mobile_phone):
            print("Please enter a valid number")
            mobile_phone = input("Enter Mobile Phone: ")

        user_id = round(time.time())
        user_data = f"user_id : {user_id} : first_name : {first_name} : last_name : {last_name} : email : {email} : password : {password} : mobile_phone : {mobile_phone}"
        save_user_data(user_data)

    view_registered_users()
    
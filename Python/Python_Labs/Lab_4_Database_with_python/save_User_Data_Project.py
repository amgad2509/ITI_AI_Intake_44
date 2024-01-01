#Append allows data to be appended to the end of the file without overwriting 
def save_user_data(user_data):
    with open("users_data.txt", "a") as file:
        file.write(user_data + "\n")

def save_project_data(project_data):
    with open("projects_data.txt", "a") as file:
        file.write(project_data + "\n")

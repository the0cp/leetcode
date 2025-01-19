import os
import re

folder_path = "src"
output_file = "README.md"

def get_title_from_filename(filename):
    name = filename[:-4]
    name = name.replace('-', ' ')
    match = re.match(r"(\d+)\.(.+)", name)
    if match:
        number = match.group(1)
        title = number + ". " + match.group(2)
        return int(number), title
    return None, None

def main():
    if not os.path.exists(folder_path):
        os.makedirs(folder_path)
    files = []
    for filename in os.listdir(folder_path):
        number, title = get_title_from_filename(filename)
        if number is not None:
            files.append((number, title, filename))
    files.sort()
    
    with open(output_file, "w") as f:
        f.write(f"# Leetcode Solutions\n\nC++ source code of solved LeetCode problems.\n\n## List\n\nThe list is sorted by problem number.\n\n<details>\n\n<summary>Expand Solution List</summary>\n\n")
        for number, title, filename in files:
            f.write(f"- [{title}](src/{filename})\n")
        f.write(f"\n</details>\n")

if __name__ == "__main__":
    main()
import os

if __name__ == "__main__":
    alert = "\033[33m[ALERT]: ARE YOU SURE TO CLEAR THE PROJECT?\033[0m\n>>> "
    ensure = input(alert)
    if (ensure == "YES"):
        SRC_DIR = os.path.join(os.path.dirname(__file__), 'src')
        SOLUTION_FOLDERS = [
            ('c', 'solutions'),
            ('cpp', 'solutions'),
            ('python', 'solutions'),
            # Add more as needed
        ]

        # Remove all files in each solutions folder
        for lang, sol_dir in SOLUTION_FOLDERS:
            folder = os.path.join(SRC_DIR, lang, sol_dir)
            if os.path.isdir(folder):
                for f in os.listdir(folder):
                    file_path = os.path.join(folder, f)
                    if os.path.isfile(file_path):
                        os.remove(file_path)

        # Clear SOL_LIST.md but keep header and problem count
        sol_list_path = os.path.join(os.path.dirname(__file__), 'SOL_LIST.md')
        if os.path.isfile(sol_list_path):
            with open(sol_list_path, 'r', encoding='utf-8') as f:
                lines = f.readlines()
            # Keep header and problem count (first 2 lines), and the three section headers
            headers = ["## 🟢Easy", "## 🟡Medium", "## 🔴Hard"]
            new_lines = lines[:2]  # header and problem count
            found = set()
            for line in lines:
                for h in headers:
                    if line.strip() == h and h not in found:
                        new_lines.append(line)
                        found.add(h)
            # Ensure a blank line at the end
            if not new_lines[-1].endswith('\n'):
                new_lines[-1] += '\n'
            with open(sol_list_path, 'w', encoding='utf-8') as f:
                f.writelines(new_lines)
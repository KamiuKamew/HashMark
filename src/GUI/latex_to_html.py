import subprocess
import os

def latex_to_html(latex_content):
    try:
        # Write LaTeX content to a temporary file
        with open('temp.tex', 'w') as f:
            f.write(latex_content)

        # Run pandoc command to convert LaTeX to HTML
        subprocess.run(['pandoc', '-s', 'temp.tex', '-o', 'output.html'])

        # Read the converted HTML content
        with open('output.html', 'rb') as f:
            html_content = f.read().decode('utf-8')  # Assuming UTF-8 encoding
        print("Current working directory:", os.getcwd())
        print("Temporary file path:", os.path.join(os.getcwd(), 'temp.tex'))
        print("Output file path:", os.path.join(os.getcwd(), 'output.html'))
        return html_content
    except Exception as e:
        print("Error:", e)
    finally:
        # Clean up temporary files
        os.remove('temp.tex')
        output_path = os.path.join(os.getcwd(), 'output.html')
        if os.path.exists(output_path):
            os.remove(output_path)
        else:
            print("File not found:", output_path)


# Example usage
if __name__ == "__main__":
    latex_content = r'\documentclass{article}\begin{document}Hello, $x^2+y^2=z^2$!\end{document}'
    html_content = latex_to_html(latex_content)
    with open('result.html', 'w', encoding='utf-8') as f:
        f.write(html_content)

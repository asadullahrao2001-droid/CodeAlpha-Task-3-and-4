
"""
==============================================
TASK: Scrape the title of a fixed webpage
       and save it to a file
CONCEPTS USED: requests, re, file handling
==============================================
"""

import requests
import re

# ---- Settings: set your URL here ----
url = "https://example.com"          # Webpage to scrape the title from
output_file = "page_title.txt"       # File to save the title into


def scrape_title(url, output_file):
    try:
        response = requests.get(url, timeout=10)
        response.raise_for_status()  # Raises an error for bad responses

        # Extract <title>...</title> from the HTML
        match = re.search(r"<title>(.*?)</title>", response.text, re.IGNORECASE | re.DOTALL)

        if match:
            title = match.group(1).strip()

            with open(output_file, "w", encoding="utf-8") as file:
                file.write(f"URL: {url}\n")
                file.write(f"Title: {title}\n")

            print(f"Title found: {title}")
            print(f"Saved to: {output_file}")
        else:
            print("No title found on this webpage.")

    except requests.exceptions.RequestException as e:
        print(f"Error while accessing the webpage: {e}")


if __name__ == "__main__":
    scrape_title(url, output_file)
    input("\nPress Enter to exit...")

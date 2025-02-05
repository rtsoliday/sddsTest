/**
 * @file searchPath.c
 * @brief Implementation of search path management and file locating functions.
 *
 * @copyright 
 *   - (c) 2002 The University of Chicago, as Operator of Argonne National Laboratory.
 *   - (c) 2002 The Regents of the University of California, as Operator of Los Alamos National Laboratory.
 *
 * @license 
 * This file is distributed under the terms of the Software License Agreement
 * found in the file LICENSE included with this distribution.
 *
 * @author H. Shang, M. Borland, R. Soliday
 */

#include "mdb.h"

static char *search_path = NULL;
/**
 * @brief Sets the search path for file lookup.
 *
 * This function updates the global `search_path` variable. If a new input path is provided,
 * it copies the input string to `search_path`, freeing any previously allocated memory.
 * If the input is `NULL`, `search_path` is set to `NULL`.
 *
 * @param input The new search path to set. If `NULL`, the search path is cleared.
 */
void setSearchPath(char *input) {
  if (search_path)
    free(search_path);
  if (input)
    cp_str(&search_path, input);
  else
    search_path = NULL;
}

/**
 * @brief Finds a file within the configured search path.
 *
 * This function searches for the specified `filename` in each directory listed in the
 * `search_path`. If the `filename` includes SDDS tags (indicated by '=' and '+'),
 * the tags are processed and appended to the found file path.
 *
 * @param filename The name of the file to locate. It may include SDDS tags in the format
 *                 `<filename>=<x>+<y>`.
 * @return A dynamically allocated string containing the path to the found file with tags,
 *         or `NULL` if the file is not found.
 */
char *findFileInSearchPath(char *filename) {
  char *path, *pathList, *tmpName;
  char *sddsTags = NULL;

  if (!filename || !strlen(filename))
    return NULL;
  if ((sddsTags = strchr(filename, '='))) {
    /* <filename>=<x>+<y> form ? */
    if (!strchr(sddsTags + 1, '+'))
      sddsTags = NULL;
    else
      /* yes */
      *sddsTags++ = 0;
  }
  if (search_path && strlen(search_path)) {
    cp_str(&pathList, search_path);
    while ((path = get_token(pathList))) {
      tmpName = malloc(strlen(filename) + strlen(path) + 2 + (sddsTags ? strlen(sddsTags) + 2 : 0));
      sprintf(tmpName, "%s/%s", path, filename);
      free(path);
      if (fexists(tmpName)) {
        if (sddsTags) {
          /* put the sddsTags back on the end */
          strcat(tmpName, "=");
          strcat(tmpName, sddsTags);
        }
        free(pathList);
        return tmpName;
      }
      free(tmpName);
    }
    free(pathList);
  }
  if (fexists(filename)) {
    if (sddsTags)
      *(sddsTags - 1) = '=';
    cp_str(&tmpName, filename);
    return tmpName;
  }
  return NULL;
}

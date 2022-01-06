#include <Windows.h>

int main(int argc, char *argv[]) {
  int value = -1;
  if (argc == 2) value = strtol(argv[1], NULL, 10);

  {
    // https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-systemparametersinfow
    int mouse_params[3];
    if (!SystemParametersInfoW(SPI_GETMOUSE, 0, mouse_params, 0))
      return EXIT_FAILURE;

    // modifying the pointer precision value,
    // toggles if no argument is given
    mouse_params[2] = (value == -1) ? !mouse_params[2] : value;

    // updating pvParam
    if (!SystemParametersInfoW(SPI_SETMOUSE, 0, mouse_params, SPIF_SENDCHANGE))
      return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

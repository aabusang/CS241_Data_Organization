#include <stdio.h>

int main()
{
  int *hours = malloc(incBy * sizeof(hours));
  int *minutes = malloc(incBy * sizeof(minutes));
  int *seconds = malloc(incBy * sizeof(seconds));
  int *ids = malloc(incBy * sizeof(ids));
  int *ages = malloc(incBy * sizeof(ages));
  int *pains = malloc(incBy * sizeof(pains));
  
  int *buffer;

  size_t incBy = 4;
    size_t maxSize = incBy, newSize;
      if ((++i) > maxSize)
    {
      newSize = (maxSize += 4) * sizeof(int *);

      /* reallocate ids */
      buffer = realloc(ids, newSize);
      if (!buffer) return 2;
      ids = buffer;

      /* reallocate time */
      buffer = realloc(hours, newSize);
      if (!buffer) return 1;
      hours = buffer;

      buffer = realloc(minutes, newSize);
      if (!buffer) return 1;
      minutes = buffer;

      buffer = realloc(seconds, newSize);
      if (!buffer) return 1;
      seconds = buffer;

      /* reallocate ages */
      buffer = realloc(ages, newSize);
      if (!buffer) return 3;
      ages = buffer;

      /* reallocated pains */
      buffer = realloc(pains, newSize);
      if (!buffer) return 4;
      pains = buffer;
    }
}

#include <cairo-pdf.h>

/*
 * Points are the unit of measurement used by Cairo. 1 point is equal to 1/72
 * inches.
 */
#define POINTS_PER_INCH 72

int main() {

  /*
   * Initialize the surface
   */
  char *filename = "hello.pdf";
  cairo_surface_t *surface = cairo_pdf_surface_create(
      filename, 8.5 * POINTS_PER_INCH, 11 * POINTS_PER_INCH);

  cairo_t *cr = cairo_create(surface);

  /*
   * Configure the style of text that is to be displayed
   */
  cairo_set_source_rgb(cr, 1, 0, 0);
  cairo_set_font_size(cr, 25.0);
  cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL,
                         CAIRO_FONT_WEIGHT_NORMAL);

  /*
   * Render the text
   */
  cairo_move_to(cr, 0, 25);
  cairo_show_text(cr, "Hello, World!");

  /*
   * Technically, we don't need to use this function because we are only
   * rendering a single page. If we were rendering multiple pages then we would
   * use multiple calls to cairo_show_page().
   */
  cairo_show_page(cr);

  /*
   * Cleanup
   */
  cairo_surface_destroy(surface);
  cairo_destroy(cr);
}

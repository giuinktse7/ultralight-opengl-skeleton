#include "web_tile.h"

WebTile::WebTile(RefPtr<Renderer> renderer, int width, int height, double scale)
{
    ViewConfig view_config;
    view_config.initial_device_scale = scale;
    view_config.is_accelerated = false;
    view_config.is_transparent = true;
    view_ = renderer->CreateView(width, height, view_config, nullptr);
}

WebTile::WebTile(RefPtr<View> existing_view)
    : view_(existing_view)
{
}

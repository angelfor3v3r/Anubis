#pragma once

// include sdk headers
#include "valve/client_entity.hpp"
#include "valve/client_entity_list.hpp"
#include "valve/client_mode.hpp"
#include "valve/engine_client.hpp"
#include "valve/engine_vgui.hpp"
#include "valve/hl_client.hpp"
#include "valve/render_view.hpp"
#include "valve/surface.hpp"
#include "valve/user_cmd.hpp"

// Team Fortress sdk headers
#include "valve/tf/c_tf_player.hpp"
#include "valve/tf/c_base_entity.hpp"

// include cheat headers
#include "shared/drawsystem/drawsystem.hpp"
#include "shared/memory.hpp"

// NOTE: Riley; For anyone reading this, a cleanup of i_client_ent* needs to be done.
// While ripping interfaces straight out of the game would make things easier. I would like
// Anubis to leave a smaller footprint in code size.
class c_tf2 {
public:
  // store all interfaces of the game
  c_engine_client*      engine_client = nullptr;
  c_hl_client*          hl_client = nullptr;
  c_engine_vgui*        engine_vgui = nullptr;
  i_surface*            surface = nullptr;
  i_client_mode_shared* client_mode = nullptr;
  i_client_entity_list* entity_list = nullptr;
  iv_render_view*       render_view = nullptr;
  //
  static bool           w2s(const vec3& origin, vec2& project);
};

class c_ctx {
public:
  c_tf_player* local_player = nullptr;

  int          screen_width = 0;
  int          screen_height = 0;

  v_matrix     matrix = {};

  void         get_local();
};

inline auto  g_draw = std::make_unique<c_draw>();
inline auto  ctx = std::make_unique<c_ctx>();
inline c_tf2 g_tf2{};
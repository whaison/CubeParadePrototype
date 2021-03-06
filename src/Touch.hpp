﻿#pragma once

//
// タッチ情報
//

namespace ngs {

struct Touch {
  // Mouse入力をタッチイベントとして扱うための識別ID
  enum { MOUSE_EVENT_ID = 0xffffffff };
  
  // OSXとWindowsとiOSの挙動の違いを吸収するwork-around
  // OSXとWindowsはmouseでの入力ならtrue
  // iOSは常にtrue
  bool prior;
  bool handled;
  
  double timestamp;
  
  u_int id;
  ci::Vec2f pos;
  ci::Vec2f prev_pos;


  // std::findを利用するための定義
  bool operator== (const Touch& rhs) const {
    return id == rhs.id;
  }

  bool operator== (const u_int rhs_id) const {
    return id == rhs_id;
  }
  
};

}

#pragma once

// - 미리컴파일된 헤더
// 1. pch.h, pch.cpp 만들기
// 2. pch.cpp에 속성 -> C/C++ -> 미리컴파일된헤더 -> 모든구성/모든플랫폼
// 3. 미리컴파일된 헤더 '만들기'
// 4. 미리컴파일된 헤더 pch.h

// 5. 프로젝트 속성 -> C/C++ -> 미리컴파일된헤더 -> 모든구성/모든플랫폼
// 6. 미리컴파일된 헤더 '사용'
// 7. 미리컴파일된 헤더 pch.h

// - ../pch.h => 포함 디렉토리
// 1. 프로젝트 속성
// 2. VC++ 디렉토리 -> 포함 디렉토리 편집
// 3. $(ProjectDir) -> 확인

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


#include <string>

#include "Creature/Creature.h"
#include "Creature/Player.h"
#include "Creature/Knight.h"
#include "Creature/Goblin.h"
#include "Creature/Archer.h"

using namespace std;


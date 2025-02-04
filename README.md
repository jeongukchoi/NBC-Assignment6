# 6번 과제 - 장애물 스테이지
[시연 영상](https://youtu.be/zUCmq_xXK4w)
## 구현된 클래스

### 필수
- MoveRailings
  - Tick 에서 DeltaTime 을 속도와 곱해 X/Y/Z 방향으로 왕복 이동하는 액터 클래스
  - 시작 위치 / 시작 각도 / 이동 속도 / 이동 범위 / 이동 방향 (축) / 랜덤화 여부
    - UPROPERTY EditAnywhere 매크로로 에디터에서 변경 가능
- MovePlatform
  - MoveRailings 를 상속하고 스태틱 메쉬만 다른 것으로 적용한 클래스
- RotateRailings
  - Tick 에서 DeltaTime 을 속도와 곱해 X/Y/Z 축 기준으로 회전하는 액터 클래스
  - 시작 위치 / 시작 각도 / 회전 속도 / 회전 기준 축 / 랜덤화 여부
    - UPROPERTY EditAnywhere 매크로로 에디터에서 변경 가능
- UEnums
  - X/Y/Z 를 열거형으로 선언
    - EAxis 는 엔진에서 이미 정의되어 있기에 EAxisType 로 선언

### 도전
- TimedPlatform
  - 월드의 TimerManager를 이용해 일정 시간마다 콜리전 활성화 여부 및 머티리얼을 변경
- PlatformSpawner
  - 초기화된 위치에서 MoveRailings 또는 RotateRailings (랜덤으로 결정) 를 스폰
  - 반복문에서 스폰된 플랫폼의 크기만큼 스폰할 위치를 옮겨 (i.e. 스폰위치 += 플랫폼 너비) 겹치지 않도록 스폰

### 추가
- GoalRailings
  - RotateRailings 를 상속하고 라이팅 및 콜리전 박스 추가
  - 콜리전 박스의 OnComponentBeginOverlap 이벤트에 플레이어 오버랩 시 시작 위치로 이동시키는 클래스 메서드를 함수 이름으로 바인드 (AddDynamic)
 
## 실행 방법
.gitignore 로 VS 나 언리얼엔진에서 생성한 캐시 등을 포함하지 않은 상태입니다.
클론을 받아 실행을 희망하시는 경우, 아래 순서대로 하면 될 것 같습니다..
1. uproject 파일 우클릭 - Generate Visual Studio project files
2. 프로젝트 파일 열어 에디터 실행
3. (위에서 안되는 경우) .sln 솔루션 파일 열기 - Build - Clean Solution - Build Solution

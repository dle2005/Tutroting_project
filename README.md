<h1> 2021 겨울방학 멘토멘티 프로그램  </h1>
<h2> Project : 토익 단어장 </h2>
</br>

<h3> 설계 프로젝트 내용 </h3>

- 본 프로젝트는 2021 겨울방학 멘토멘티 프로그램 프로젝트로, C프로그래밍 기초 완성, 포인터, 링크드 리스트 개념을 이해하고 링크드 리스트를 활용한 설계 프로젝트 입니다.
- 본 프로젝트는 사용자가 토익 단어를 학습할 수 있는 기능을 제공하는 것을 목표로 한다.
- 사용자는 토익 단어를 보고 학습할 수 있으며, 문제 풀이가 가능하다.
- 유저 정보에 관한 데이터베이스를 구축하여, 사용자 정의 단어장과 그에 관한 문제 풀이도 가능 하다.

</br>

<h3> 설계 프로젝트 요구 사항 분석 </h3>

1. 프로그램 실행 시, 사용자는 로그인, 회원가입을 선택 할 수 있다.
2. 로그인의 경우 등록 유저인지 검사하여 유효한 경우 로그인이 되어 다음 화면으로 이동한다.
3. 회원가입의 경우 아이디와 비밀번호를 입력받아 저장하며, 프로그램 시작 화면으로 이동한다.
4. 로그인이 성공하면 단어장, 단어 퀴즈, 사용자 정의 단어장, 사용자 정의 단어 퀴즈가 선택 가능하다.
5. 단어장은 단어 한영 또는 영한으로 단어 검색이 가능하며, 미리 등록한 100개의 단어 목록을 1페이지당 10개의 단어를 출력하여 보여준다. 
6. 단어 퀴즈는 한영 또는 영한, 주관식, 객관식이 선택 가능하며 등록된 100개의 단어중 10문제가 출제 된다. 
7. 사용자 정의 단어장은 사용자로 부터 단어를 입력 받아 데이터베이스에 추가가 가능하며, 단어장 기능과 같이 목록으로 출력이 가능하다.
8. 사용자 정의 단어 퀴즈는 사용자가 등록 단어에서 단어 퀴즈와 같이 문제가 출제 된다.

</br>

<h3> 설계 프로젝트 상세 설계 </h3>

- 헤더 파일
    - 유저의 아이디와 비밀번호가 저장될 구조채 선언
        - User id[20], pw[20]
    - 단어의 영문과 한글이 저장될 구조체 선언
        - Word eng_name[20], kor_name[20]
    - 로그인 유저 정보를 전역변수로 선언
        - User login_user

- 로그인
    - 사용자로부터 아이디 비밀번호 입력 받음
    - UserInfo.txt에서 입력 정보로 부터 등록 유저인지 탐색
    - 로그인 성공시 다음 화면으로 이동, 전역변수에 정보 저장
    - 에러 처리
        - 입력 아이디와 비밀번호는 1~9자리
        - 아이디가 없는경우, 비밀번호가 다른경우 알림 후 다시 입력 받음

- 회원가입
    - 사용자로부터 아이디 비밀번호를 입력 받음
    - UserInfo.txt에 입력 정보를 저장
    - 회원가입 완료시 시작 화면으로 이동
    - 에러 처리
        - 입력 아이디와 비밀번호는 1~9자리
        - 아이디 중복시 알림 후 다시 입력 받음

- 단어장
    - 매개변수로 사용할 파일 이름을 입력 받음
    - 한 페이지당 10개의 문제를 출력
    - 하단에 현재 페이지와 최대 페이지를 출력
    - 키보드 '<-' '->' 입력시 페이지 이동
    - ESC 입력시 종료
    - 에러 처리
        - 파일이 존재하지 않을시 알림 후 이전 페이지로 이동
        - 존재하지 않는 페이지로는 이동 불가

- 검색
    - 단어장에서 사용자 정의 단어장이 아닌 경우 선택 가능
    - 기존 등록된 단어 목록에서 검색을 실시
    - 영한 또는 한영이 선택 가능

- 단어 퀴즈
    - 매개변수로 사용할 파일 이름을 입력 받음
    - 객관식, 주관식(4지 선다) 선택 가능
    - 한영, 영한 문제풀이 선택 가능
    - 상단에 현재 진행도(%)를 출력
    - 풀이가 완료되면 정확도(%) 및 틀린단어를 출력
    - 에러 처리
        - 파일이 존재하지 않을시 알림 후 이전 페이지로 이동

- 케이스 스타일
    - 카멜 케이스: 함수명
    - 파스칼 케이스: 구조체, 파일명, 상수, 전역변수
    - 스네이크 케이스: 변수명

</br>

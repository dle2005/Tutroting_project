<h1> 2021 겨울방학 멘토멘티 프로그램  </h1>
<h2> Project : 토익 단어장 </h2>
</br>

- 케이스 스타일
    - 카멜 케이스: 함수명
    - 파스칼 케이스: 구조체, 파일명, 상수, 전역변수
    - 스네이크 케이스: 변수명

- 프로젝트 구현 내용
    1. 프로그램 실행  
        - 로그인, 회원가입 선택
        - 1. 로그인  
            2. 회원가입
    1. 로그인 구현
        - UserInfo 구조체 사용
            - char user_id[20]
            - char password[20]
        - ID, Password를 입력받아, 'UserInfo.txt' 파일을 열어 아이디와 비밀번호를 탐색, 등록된 유저인 경우 로그인
            - 아이디 혹은 비밀번호가 다를시 에러 처리
        - 로그인 성공 시 메인 화면으로 이동
            - 유저 아이디를 전역변수에 저장
    1. 회원가입 구현
        - UserInfo 구조체 사용
        - 사용자가 입력한 아이디, 비밀번호를 'UserInfo.txt'에 저장
            - 아이디 중복 검사, 중복 시 에러 처리
        - 회원가입 완료 시 프로그램 실행 화면으로 이동
    1. 메인 화면
        - 단어장, 단어 퀴즈 선택
        - 1. 단어장
            2. 단어 퀴즈
    1. 단어장 구현
        - Word 구조체 사용
            - char eng_name[20]
            - char kor_name[20]
        - 'Wordbook.txt' 에 토익 단어 가져와서 저장
        - 'Wordbook.txt' 파일을 열어 한 페이지당 10단어를 출력
        - 이전, 다음 페이지 이동 기능
            - 키보드 '<-' '->' 입력시 페이지 이동
            - 하단에 이전[<-] 1(페이지 번호) 다음[->] 출력 
        - 종료 기능 추가()
    1. 단어 퀴즈 구현
        - 'Wordbook.txt' 파일을 열어 한 문제씩 영문만 보여주고 뜻을 입력받음
            - ex) school : <입력>
            - enter 입력시 다음 문제로 이동
        - 10문제를 기준으로 진행률(%) 한줄 위 우측 상단 표시
            - ex) 1/10 (10%)
        - 풀이가 완료되면, 정확도(%) 및 틀린단어 출력, 유저별로 오답노트 파일을 생성 틀린단어를 저장
            - 오답노트는 틀린 답 입력시 링크드 리스트에 추가
            - 유저아이디.txt 파일 생성해서 오답 저장

    - 추후 업데이트 예정
        1. 회원정보 수정
        2. 트리 이용해서 정렬기능
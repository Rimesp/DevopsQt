pipeline {
    agent any
    stages {
        stage('Checkout') {
            steps {
                echo 'Checking out code from GitHub'
                git 'https://github.com/Rimesp/DevopsQt.git'
            }
        }
        stage('Build') {
            steps {
                script {
                    // Print the current directory for debugging
                    bat 'echo Current directory: %CD%'
                    bat 'echo Workspace directory: %WORKSPACE%'

                    // Set up Visual Studio environment and build
                    bat '''
                    "C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\Community\\VC\\Auxiliary\\Build\\vcvars64.bat"
                    echo Checking for cl.exe
                    where cl
                    echo Running qmake
                    "C:\\Qt\\5.15.2\\msvc2019_64\\bin\\qmake.exe" QtDev.pro
                    echo Running nmake
                    nmake
                    '''
                }
            }
        }
        stage('Test') {
            steps {
                echo 'Running simplified test...'
            }
        }
        stage('Deploy to Local Machine') {
            steps {
                // Check if the SSH key file exists and is accessible
                bat 'dir C:\\Users\\rimouertani\\.ssh'
                bat 'icacls C:\\Users\\rimouertani\\.ssh\\id_rsa'

                // Perform the SCP command
                bat 'scp -i C:\\Users\\rimouertani\\.ssh\\id_rsa -P 22 rim@40.127.8.223:C:\\Users\\rim\\Documents\\QtDev\\DevopsQt\\build\\Desktop_Qt_5_15_2_MSVC2019_64bit-Debug\\debug\\QtDev.exe C:\\Users\\rimouertani\\DeployedApp\\'
            }
        }
    }
    post {
        always {
            echo 'Archiving build artifacts'
            archiveArtifacts artifacts: '**/build/Desktop_Qt_5_15_2_MSVC2019_64bit-Debug/debug/*.exe', allowEmptyArchive: false
            echo 'Performing cleanup'
            // Add cleanup commands if necessary
        }
    }
}

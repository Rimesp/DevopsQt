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
                echo 'Add your test steps here'
                // Add your test commands or scripts here
            }
        }
        stage('Deploy') {
            steps {
                echo 'Add your deployment steps here'
                // Add your deployment commands or scripts here
            }
        }
    }
    post {
        always {
            echo 'Archiving build artifacts'
            archiveArtifacts artifacts: 'C:/Users/rim/Documents/QtDev/DevopsQt/build/*.exe', allowEmptyArchive: true
            echo 'Performing cleanup'
            // Add cleanup commands if necessary
        }
    }
}

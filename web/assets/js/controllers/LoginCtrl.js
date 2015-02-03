define(function(require) {
  'use strict';
  /*
   * Login controller
   */
  return function($log, $scope, AuthService) {
    $log.info('Initializing LoginCtrl');

    $scope.username = AuthService.username;
    $scope.image = '';
    $scope.message = '';
    $scope.loginInProgress = false;

    /*
     * Send the login request
     */
    $scope.submitLogin = function() {
      if ($scope.loginInProgress) {
        return;
      }
      $scope.loginInProgress = true;
      AuthService.sendLogin($scope.username, $scope.image, function(err, result) {
        $scope.loginInProgress = false;
        if (err) {
          $scope.message = "Error: " + err.message;
          return;
        }
        $log.info('Login ok for ' + $scope.username);
        AuthService.authOK($scope.username, result);
      });
    };
  };
});